#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <unordered_set>
#include "pin.H"

// Using, std::unordered_set for fast lookup
static const std::unordered_set<ADDRINT> NOT_SKIP_INSTRS = {
    0x1615ab,0x1615af,0x1615b8,0x161642,0x161646,0x161704,0x161708,0x1617d5,0x1617d9,0x1617dd,0x161b20,0x161b24,0x161b28,0x161d9d,0x1620e5,0x1620e9,0x1620f2,0x1625f7,0x162674,0x1626b3,0x162706,0x1629f8,0x162a42,0x162d71,0x162de3,0x162de6,0x162e8b,0x162e8e,0x163231,0x16362c,0x163635,0x163638,0x16363d,0x22feae,0x22feee,0x22ff91,0x22ff95,0x22ff9d,0x2300a2,0x2300a6,0x2300ae,0x230116,0x2301a5,0x2301a9,0x2301b1,0x2301b5,0x2301ba,0x2301c1,0x230267,0x2302b4,0x2302b8,0x230315,0x230319,0x23031d,0x230321,0x230569,0x230572,0x23057a,0x23057f,0x230583,0x230587,0x23065b,0x2306af,0x2306b6,0x2306f1,0x23074c,0x23084a,0x230985,0x230b68,0x230bca,0x230c3d,0x230cbd,0x230d5e,0x230dd3,0x230dda,0x230e9c,0x230f12,0x230f95,0x23103b,0x23103f,0x231180,0x2311ec,0x2311f0,0x2311f4,0x231254,0x2313d8,0x23144f,0x231452,0x2314af,0x231518,0x231625,0x2316ac,0x231962,0x231965,0x2319d5,0x231a67,0x231a6a,0x231b4e,0x231b6c,0x231b70,0x231c44,0x231cc5,0x231d82,0x231e19,0x231eab,0x231f76,0x231fa8,0x231fac,0x231faf,0x231fb4,0x231fb8,0x231fbc,0x231fe7,0x231feb,0x231fef,0x231ff4,0x232114,0x232117,0x232210,0x23229c,0x2323c4,0x232531,0x23259b,0x232614,0x23261b,0x232683,0x232686,0x232713,0x232717,0x23271b,0x2328a2,0x2328a5,0x23292f,0x232932,0x2329c7,0x232a7a,0x232a7e,0x232b2e,0x232c6b,0x232c91,0x232c93,0x232c95,0x232cf2,0x232d52,0x232e82,0x232ff7,0x232ffa,0x233090,0x233094,0x233098,0x23318f,0x2331cd,0x2331c9,0x2331d1,0x233260,0x233265,0x23326d,0x2332f2,0x23340e,0x2334a0,0x23355c,0x2336db,0x2336dd,0x23378f,0x233793,0x2337da,0x23383c,0x2338d5,0x233971,0x2339f0,0x233aae,0x233be6,0x233bee,0x233d3b,0x233dfa,0x233e5e,0x233eec,0x233ef0,0x233ef4,0x233f81,0x233f84,0x233fd4,0x23401f,0x23408a,0x23408e,0x234091,0x234166,0x23416a,0x23416d,0x2341d9,0x2342d2,0x2344a4,0x2344a7,0x2344e9,0x2344ed,0x23458b,0x234623,0x234656,0x23465a,0x234761,0x2348fd,0x234901,0x234905,0x23495a,0x234a53,0x234ad0,0x234b46,0x234b49,0x234db5,0x234e2b,0x234e86,0x234e8a,0x234ee3,0x234f41,0x234fdd,0x23502e,0x2351a5,0x235321,0x235325,0x235389,0x2353fa,0x23549c,0x2354a1,0x2354d3,0x2354d7,0x2354de,0x2354e5,0x2354e9,0x2354ed,0x2354f1,0x2354f5,0x235546,0x23554a,0x2355c5,0x2355c9,0x2355d0,0x2355d7,0x2355db,0x2355df,0x2355e3,0x2355e7,0x2358da,0x235957,0x2359f9,0x2359fd,0x235bcf,0x235c29,0x235c8f,0x235ce6,0x235cea,0x235dd4,0x236013,0x236065,0x2360b9,0x23623e,0x236242,0x236245,0x2362ca,0x236345,0x2363d7,0x236629,0x23689c,0x2368c3,0x236948,0x23697a,0x236d67,0x236d73,0x236d78,0x236e62,0x236e66,0x236e69,0x23707a,0x23707e,0x237082,0x2370aa,0x2370ae,0x2370b1,0x2371a9,0x23720e,0x237281,0x23757f,0x237583,0x2375b0,0x2375b3,0x2375b7,0x237669,0x2377e2,0x2377e5,0x237971,0x2379bc,0x2379bf,0x2379f4,0x2379f7,0x237a40,0x237a3c,0x237a34,0x237a31,0x237abb,0x237f8f,0x237f93,0x237f97,0x238010,0x238107,0x2382fb,0x2382f7,0x238360,0x238364,0x238367,0x2384a9,0x2384ad,0x22feae,0x230219,0x230227,0x236d6f};
   
static const std::unordered_set<ADDRINT> INITIAL_INSTRS = {
    0x23009d, 0x162d68, 0x163625, 0x22ff8c, 0x23009, 0x230747, 0x230bc1, 0x231247, 0x231fa3, 0x231fe2, 0x23201a, 0x232c8c, 0x23325b, 0x2336d6, 0x233be1, 0x233e59, 0x233f7c, 0x234085, 0x23449f, 0x234651, 0x2354ce, 0x2355c0, 0x235ec7, 0x235f95, 0x23600e, 0x236d62, 0x236e5d, 0x2370a5, 0x2371a4, 0x2377dd, 0x2379b7, 0x2379ef, 0x237a2c, 0x237ab6, 0x238104};

static const std::unordered_set<ADDRINT> BYTECODE_INSTR ={
    0x1615a7,0x161639,0x161700,0x1617d1,0x161b1c,0x161d99,0x161ef0,0x1620e1,0x1622b3,0x162300,0x1625ee,0x162621,0x162670,0x1626af,0x162702,0x162768,0x1629f4,0x162a3e,0x162d75,0x162ddf,0x162e87,0x16322c,0x163641,0x16367a,0x1a7be1,0x22feea,0x22ff2d,0x22ff99,0x22ffd4,0x2300aa,0x230112,0x2301a1,0x23025e,0x2302b0,0x2302f5,0x230311,0x2304a3,0x230565,0x2305dd,0x230651,0x2306ab,0x2306ed,0x230750,0x230846,0x230926,0x23097c,0x230b64,0x230bce,0x230c38,0x230cb8,0x230d55,0x230dcf,0x230e99,0x230f0d,0x230f91,0x231036,0x231177,0x2311e8,0x231250,0x2313cf,0x231446,0x2314ab,0x23150f,0x23161c,0x2316a3,0x2316d2,0x23195e,0x2319d1,0x231a5e,0x231ab1,0x231b45,0x231b68,0x231bba,0x231c3b,0x231cc0,0x231d7e,0x231e15,0x231ea2,0x231f6d,0x231fc0,0x231ff9,0x232039,0x232110,0x23220c,0x232293,0x23236e,0x23252d,0x232592,0x232610,0x23267f,0x23270f,0x232899,0x232926,0x2329be,0x232a76,0x232b25,0x232bc4,0x232c62,0x232c9a,0x232ce9,0x232d49,0x232e79,0x232fee,0x23308c,0x233186,0x2331c5,0x233268,0x2332e9,0x233365,0x233405,0x23349b,0x233553,0x2335f3,0x2336e1,0x23378b,0x2337d6,0x233833,0x2338cc,0x23396c,0x2339e7,0x233aaa,0x233bea,0x233d32,0x233d8c,0x233df1,0x233e62,0x233ee8,0x233f88,0x233fcb,0x23401b,0x234095,0x234162,0x2341d0,0x2342c6,0x23435d,0x234448,0x2344ab,0x2344e5,0x234582,0x23461f,0x234667,0x234758,0x2348f9,0x234951,0x2349b7,0x234a4f,0x234ac7,0x234b3d,0x234db1,0x234e27,0x234e82,0x234eda,0x234f38,0x234fd4,0x235025,0x23518e,0x23531d,0x235380,0x2353f1,0x235498,0x2354f9,0x235542,0x235595,0x2355eb,0x2358d1,0x235952,0x2359f5,0x235bc6,0x235c20,0x235c86,0x235ce2,0x235d51,0x235d78,0x235dd0,0x235ecc,0x235eed,0x235f9a,0x236017,0x23605c,0x2360b0,0x2361ae,0x23621e,0x23623a,0x2362c1,0x23633c,0x2363b1,0x2363d3,0x236625,0x23680f,0x236893,0x2368bf,0x23693f,0x236971,0x236d24,0x236d6b,0x236e6d,0x236ea4,0x236fc6,0x237022,0x237054,0x2370b5,0x2371ad,0x237205,0x23727d,0x2373eb,0x23757b,0x2375ac,0x2375f2,0x237660,0x2377e9,0x237839,0x23794a,0x237969,0x2379c3,0x2379fb,0x237a38,0x237abf,0x237cb5,0x237eda,0x237f21,0x237f8b,0x238007,0x238087,0x2380e2,0x23810a,0x238293,0x2382d7,0x2382f3,0x23835c,0x2383bd,0x23847c,0x2384a4,0x238512,0x22feaa,0x2349b7,0x236d24,0x236fc6,0x237022,0x2375f2,0x237cb5,0x237eda,0x237f21,0x2380e2
    };

static const std::unordered_set<ADDRINT> DISPATCH_TABLE_INSTRS ={
    0x2300c1, 0x22ff06, 0x1615cc,0x161659,0x161720,0x1617f5,0x161b40,0x161db6,0x161f09,0x162106,0x1622cc,0x162319,0x16260a,0x16263a,0x16268c,0x1626cc,0x16271e,0x162781,0x162a10,0x162a5a,0x162d89,0x162dfe,0x162ea6,0x16324a,0x163655,0x163693,0x1a7bef,0x22ff46,0x22ffb0,0x22fff0,0x23012e,0x2301d7,0x23027a,0x2302d0,0x23033e,0x2304bd,0x23059b,0x2306cd,0x230709,0x230862,0x230999,0x230b81,0x230be2,0x230d72,0x230df1,0x230eb4,0x230fae,0x23105b,0x231193,0x23120c,0x231267,0x2313eb,0x231465,0x2314c7,0x23152c,0x231638,0x2316c0,0x23197e,0x2319ed,0x231a7e,0x231acd,0x231b62,0x231b89,0x231c58,0x231d9a,0x231e31,0x231ebf,0x231f89,0x231fd4,0x23200d,0x23204d,0x23212f,0x232228,0x2322b0,0x2323cc,0x232549,0x2325af,0x232632,0x23269f,0x232733,0x2328be,0x232946,0x2329db,0x232a96,0x232b42,0x232bdd,0x232c7f,0x232d05,0x232d65,0x232e95,0x233013,0x2330b0,0x2331a3,0x2331e9,0x233306,0x233422,0x233570,0x23360c,0x2337ab,0x2337f2,0x23384f,0x2338e8,0x233a03,0x233ac6,0x233c01,0x233d4e,0x233da5,0x233e0d,0x233f0d,0x233f9c,0x233fe7,0x234037,0x2340a9,0x234186,0x2341ec,0x2342e6,0x2344bf,0x234505,0x23459e,0x23463c,0x23466f,0x234775,0x23491e,0x23496d,0x2349cf,0x234a6b,0x234ae3,0x234b5c,0x234dcd, 0x234e43,0x234ea2,0x234ef6,0x234f54,0x234ff0,0x235041,0x23533d,0x23539c,0x23540d,0x2354b9,0x23550d,0x235562,0x2355ff,0x2358ed,0x235a15,0x235be2,0x235c3c,0x235ca2,0x235d02,0x235d6d,0x235d94,0x235f06,0x236078,0x2360cc,0x2361ca,0x23625e,0x236358,0x2363f0,0x236641,0x2368af,0x2368dc,0x23695c,0x236d3c,0x236e81,0x236ebd,0x236fde,0x23703a,0x237070,0x23709a,0x2370c9,0x237221,0x237299,0x237404,0x23759b,0x2375cf,0x23760a,0x23767d,0x2377fd,0x237963,0x237989,0x2379d7,0x237a53,0x237ccd,0x237ef2,0x237f39,0x237faf,0x238024,0x2380fa,0x238123,0x2382af,0x238313,0x238380,0x238494,0x23852a,0x2349cf,0x236d3c,0x236fde,0x23703a,0x23760a,0x237ccd,0x237ef2,0x237f39,0x2380fa
    };

static const std::unordered_set<ADDRINT> NORMAL_DISPATCH_JUMP = {
    0x2300c5, 0x1615d0,0x22ff0a,0x22ff4a,0x22ffb4,0x22fff4,0x230132,0x2301db,0x23027e,0x2302d4,0x230342,0x2304c1,0x23059f,0x2306d1,0x23070d, 0x230866,0x23099d,0x230b85,0x230be6,0x230d76,0x230df5,0x230eb8,0x230fb2,0x23105f,0x231197,0x231210,0x23126b,0x2313ef,0x231469,0x2314cb,0x231530,0x23163c,0x2316c4,0x231982,0x2319f1,0x231a82,0x231ad1,0x231b66,0x231b8d,0x231c5c,0x231d9e,0x231e35,0x231ec3,0x231f8d,0x231fd8,0x232011,0x232051,0x232133,0x23222c,0x2322b4,0x23254d,0x2325b3,0x232636,0x2326a3,0x232737,0x2328c2,0x23294a,0x2329df,0x232a9a,0x232b46,0x232be1,0x232c83,0x232d09,0x232d69,0x232e99,0x233017,0x2330b4,0x2331a7,0x2331ed,0x23330a,0x233426,0x233574,0x233610,0x2337af,0x2337f6,0x233853,0x2338ec,0x233a07,0x233aca,0x233c05,0x233d52,0x233da9,0x233e11,0x233f11,0x233fa0,0x233feb,0x23403b,0x2340ad,0x23418a,0x2341f0,0x2342ea,0x234509,0x2344c3, 0x2345a2,0x234640,0x234673,0x234779,0x234922,0x234971,0x2349d3,0x234a6f,0x234ae7,0x234b60,0x234dd1,0x234e47,0x234ea6,0x234efa,0x234f58,0x234ff4,0x235045,0x235341,0x2353a0,0x235411,0x2354bd,0x235511,0x235566,0x235603,0x2358f1,0x235a19,0x235be6,0x235c40,0x235ca6,0x235d06,0x235d71,0x235d98,0x235f0a,0x23607c,0x2360d0,0x2361ce,0x236262,0x23635c,0x2363f4,0x236645,0x236828,0x2368b3,0x2368e0,0x236960,0x236d40,0x236e85,0x236ec1,0x236fe2,0x23703e,0x237074,0x237076,0x23709e,0x2370cd,0x237225,0x23729d,0x237408,0x23759f,0x2375d3,0x23760e,0x237681,0x237801,0x237967,0x23798d,0x2379db,0x237a57,0x237cd1,0x237ef6,0x237f3d,0x237fb3,0x238028,0x2380fe,0x238127,0x2382b3,0x238384,0x238498,0x23852e,0x238317,0x2349d3,0x236d40,0x236fe2,0x23703e,0x23760e,0x237cd1,0x237ef6,0x237f3d,0x2380fe
    };

static const std::unordered_set<ADDRINT> COMBINED_DISPATCH_JUMPS = {
    0x23066f,0x23022b,0x23030e,0x2305f6,0x230764,0x23093f,0x230c56,0x230cd6,0x230f2b,0x2316eb,0x231bd3,0x231cde,0x232387,0x232cae,0x233281,0x23337e,0x2334b9,0x2336f5,0x23398a,0x233e76,0x234376,0x234461,0x2351a8,0x2355ae,0x235970,0x235ded,0x235ee0,0x235fae,0x23602b,0x236237,0x2362de,0x2363ca,0x236828,0x23698e,0x236d7c,0x2371c1,0x237852,0x237a0f,0x237ad3,0x2380a0,0x2382f0,0x2383d6,0x2384c6,0x22fec2};

static const std::unordered_set<ADDRINT> OTHER_DISPATCH_JUMPS = {
    0x25ef16,0x25f5bc,0x25faac,0x25fcf1,0x2601df,0x260dcb,0x2dfcc4,0x2dfe7a,0x2dff40,0x2dffb7,0x2e00d6,0x2e0185,0x2e042a,0x2e0667,0x2e0a38,0x2e0aa8,0x2e0c89,0x2e0ce5,0x2e112e,0x2e1393};

#endif