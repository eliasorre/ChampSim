#include <algorithm>
#include <math.h>
#include <stack>

#include "cache.h"
#include "ooo_cpu.h"
#define MAX_PFETCHQ_ENTRIES 128
#define MAX_RECENT_PFETCH 4

std::deque<std::tuple<uint64_t, uint64_t>> prefetch_queue; // Storage: 64-bits * 48 (queue size) = 384 bytes
std::deque<uint64_t> recent_prefetches;                             // Storage: 64-bits * 10 (queue size) = 80 bytes

void CACHE::prefetcher_initialize() {}

void CACHE::prefetcher_branch_operate(uint64_t ip, uint8_t branch_type, uint64_t branch_target)
{
//   if(!(ip % 4 == 0 and branch_target % 4 == 0)) fmt::print(stderr, "[FDIP] error IP: {}, Branch Target: {} \n", ip, branch_target);
  uint64_t block_addr = ((branch_target >> LOG2_BLOCK_SIZE) << LOG2_BLOCK_SIZE);
  if (block_addr == 0)
    return;

  auto it = std::find_if(prefetch_queue.begin(), prefetch_queue.end(),
                         [block_addr](std::tuple<uint64_t, uint64_t> x) { return block_addr == std::get<0>(x); });
  if (it == prefetch_queue.end()) {
    std::deque<uint64_t>::iterator it1 = std::find(recent_prefetches.begin(), recent_prefetches.end(), block_addr);
    if (it1 == recent_prefetches.end()) {
      prefetch_queue.push_back({block_addr, branch_target});
    }
    if (prefetch_queue.size() > MAX_PFETCHQ_ENTRIES) {
        prefetch_queue.pop_front();
    }
  }
}

uint32_t CACHE::prefetcher_cache_operate(uint64_t addr, uint64_t ip, uint64_t instr_id, uint8_t cache_hit, bool prefetch_hit, uint8_t type, uint8_t, uint32_t metadata_in)
{
    // if(!(addr % 4 == 0)) fmt::print(stderr, "[FDIP] error ADDR: {} \n", addr, ip);

    if ((cache_hit == 0) && (get_mshr_occupancy() < get_mshr_size() >> 1)) {
        uint64_t pf_addr = addr + (1 << LOG2_BLOCK_SIZE);
        prefetch_line(pf_addr, true, 0);
        recent_prefetches.push_back(pf_addr);
        if (recent_prefetches.size() > MAX_RECENT_PFETCH) {
            recent_prefetches.pop_front();
        }
    }
    return metadata_in;
}

void CACHE::prefetcher_cycle_operate()
{
  while (prefetch_queue.size()) {
    if (get_mshr_occupancy() < get_mshr_size() >> 1) {
        auto it = std::find(recent_prefetches.begin(), recent_prefetches.end(), std::get<0>(prefetch_queue.front()));
        if (hit_test(std::get<1>(prefetch_queue.front()))) {
            prefetch_queue.pop_front();
            continue;
        }
        if (it == recent_prefetches.end()) {
            prefetch_line(std::get<0>(prefetch_queue.front()), true, 0);
            recent_prefetches.push_back(std::get<0>(prefetch_queue.front()));
        } else {
            continue; // note: if all goes well we never end up here...
        }
        if (recent_prefetches.size() > MAX_RECENT_PFETCH) {
            recent_prefetches.pop_front();
        }
        prefetch_queue.pop_front();
    }
    return;
  }
}


uint32_t CACHE::prefetcher_cache_fill(uint64_t v_addr, uint32_t set, uint32_t way, uint8_t prefetch, uint64_t evicted_v_addr, uint32_t metadata_in)
{
  return metadata_in;
}

void CACHE::prefetcher_final_stats() {}
void CACHE::prefetcher_squash(uint64_t ip, uint64_t instr_id) {}
