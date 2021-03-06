
// COPYRIGHT_BEGIN
//
// The MIT License (MIT)
//
// Copyright (c) 2015-2020 Wizzer Works
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
//
//  For information concerning this source file, contact Mark S. Millard,
//  of Wizzer Works at msm@wizzerworks.com.
//
//  More information concerning Wizzer Works may be found at
//
//      http://www.wizzerworks.com
//
// COPYRIGHT_END

// include Magic Lantern math header files
#include "math/scalar.h"
#include "math/angle.h"
#include "math/asine.h"

// include Magic Lantern kernel header files
#include "mle/mlAssert.h"


#if ML_FIXED_POINT

#ifdef WRITE_LUT
static short arcsinLUT[] = { 1,2,3,4 };

#else  /* WRITE_LUT */

// Insert mlto-generated LUT here...

#if ML_FIXED_RADIX == 16
static short arcsinLUT[] = { 
    0x0, 0xa, 0x14, 0x1e, 0x28, 0x32, 0x3d, 0x47, 
    0x51, 0x5b, 0x65, 0x70, 0x7a, 0x84, 0x8e, 0x98, 
    0xa2, 0xad, 0xb7, 0xc1, 0xcb, 0xd5, 0xe0, 0xea, 
    0xf4, 0xfe, 0x108, 0x113, 0x11d, 0x127, 0x131, 0x13b, 
    0x145, 0x150, 0x15a, 0x164, 0x16e, 0x178, 0x183, 0x18d, 
    0x197, 0x1a1, 0x1ab, 0x1b5, 0x1c0, 0x1ca, 0x1d4, 0x1de, 
    0x1e9, 0x1f3, 0x1fd, 0x207, 0x211, 0x21c, 0x226, 0x230, 
    0x23a, 0x244, 0x24e, 0x259, 0x263, 0x26d, 0x277, 0x282, 
    0x28c, 0x296, 0x2a0, 0x2aa, 0x2b5, 0x2bf, 0x2c9, 0x2d3, 
    0x2dd, 0x2e8, 0x2f2, 0x2fc, 0x306, 0x310, 0x31b, 0x325, 
    0x32f, 0x339, 0x344, 0x34e, 0x358, 0x362, 0x36c, 0x377, 
    0x381, 0x38b, 0x395, 0x3a0, 0x3aa, 0x3b4, 0x3be, 0x3c8, 
    0x3d3, 0x3dd, 0x3e7, 0x3f1, 0x3fc, 0x406, 0x410, 0x41a, 
    0x425, 0x42f, 0x439, 0x443, 0x44d, 0x458, 0x462, 0x46c, 
    0x477, 0x481, 0x48b, 0x495, 0x49f, 0x4aa, 0x4b4, 0x4be, 
    0x4c9, 0x4d3, 0x4dd, 0x4e7, 0x4f2, 0x4fc, 0x506, 0x510, 
    0x51b, 0x525, 0x52f, 0x53a, 0x544, 0x54e, 0x558, 0x563, 
    0x56d, 0x577, 0x581, 0x58c, 0x596, 0x5a0, 0x5ab, 0x5b5, 
    0x5bf, 0x5c9, 0x5d4, 0x5de, 0x5e8, 0x5f2, 0x5fd, 0x607, 
    0x611, 0x61c, 0x626, 0x630, 0x63b, 0x645, 0x64f, 0x65a, 
    0x664, 0x66e, 0x678, 0x683, 0x68d, 0x697, 0x6a2, 0x6ac, 
    0x6b6, 0x6c1, 0x6cb, 0x6d5, 0x6e0, 0x6ea, 0x6f4, 0x6ff, 
    0x709, 0x713, 0x71e, 0x728, 0x733, 0x73d, 0x747, 0x752, 
    0x75c, 0x766, 0x771, 0x77b, 0x785, 0x790, 0x79a, 0x7a4, 
    0x7af, 0x7b9, 0x7c4, 0x7ce, 0x7d8, 0x7e3, 0x7ed, 0x7f7, 
    0x802, 0x80c, 0x817, 0x821, 0x82b, 0x836, 0x840, 0x84a, 
    0x855, 0x85f, 0x86a, 0x874, 0x87f, 0x889, 0x893, 0x89e, 
    0x8a8, 0x8b3, 0x8bd, 0x8c8, 0x8d2, 0x8dc, 0x8e7, 0x8f1, 
    0x8fc, 0x906, 0x911, 0x91b, 0x925, 0x930, 0x93a, 0x945, 
    0x94f, 0x95a, 0x964, 0x96f, 0x979, 0x984, 0x98e, 0x999, 
    0x9a3, 0x9ae, 0x9b8, 0x9c2, 0x9cd, 0x9d7, 0x9e2, 0x9ec, 
    0x9f7, 0xa01, 0xa0c, 0xa16, 0xa21, 0xa2b, 0xa36, 0xa40, 
    0xa4b, 0xa55, 0xa60, 0xa6b, 0xa75, 0xa80, 0xa8a, 0xa95, 
    0xa9f, 0xaaa, 0xab4, 0xabf, 0xac9, 0xad4, 0xade, 0xae9, 
    0xaf4, 0xafe, 0xb09, 0xb13, 0xb1e, 0xb28, 0xb33, 0xb3e, 
    0xb48, 0xb53, 0xb5d, 0xb68, 0xb73, 0xb7d, 0xb88, 0xb92, 
    0xb9d, 0xba8, 0xbb2, 0xbbd, 0xbc8, 0xbd2, 0xbdd, 0xbe7, 
    0xbf2, 0xbfd, 0xc07, 0xc12, 0xc1d, 0xc27, 0xc32, 0xc3d, 
    0xc47, 0xc52, 0xc5d, 0xc67, 0xc72, 0xc7d, 0xc87, 0xc92, 
    0xc9d, 0xca7, 0xcb2, 0xcbd, 0xcc8, 0xcd2, 0xcdd, 0xce8, 
    0xcf2, 0xcfd, 0xd08, 0xd13, 0xd1d, 0xd28, 0xd33, 0xd3e, 
    0xd48, 0xd53, 0xd5e, 0xd69, 0xd73, 0xd7e, 0xd89, 0xd94, 
    0xd9e, 0xda9, 0xdb4, 0xdbf, 0xdca, 0xdd4, 0xddf, 0xdea, 
    0xdf5, 0xe00, 0xe0a, 0xe15, 0xe20, 0xe2b, 0xe36, 0xe41, 
    0xe4c, 0xe56, 0xe61, 0xe6c, 0xe77, 0xe82, 0xe8d, 0xe98, 
    0xea2, 0xead, 0xeb8, 0xec3, 0xece, 0xed9, 0xee4, 0xeef, 
    0xefa, 0xf05, 0xf10, 0xf1a, 0xf25, 0xf30, 0xf3b, 0xf46, 
    0xf51, 0xf5c, 0xf67, 0xf72, 0xf7d, 0xf88, 0xf93, 0xf9e, 
    0xfa9, 0xfb4, 0xfbf, 0xfca, 0xfd5, 0xfe0, 0xfeb, 0xff6, 
    0x1001, 0x100c, 0x1017, 0x1022, 0x102d, 0x1038, 0x1043, 0x104e, 
    0x1059, 0x1064, 0x106f, 0x107a, 0x1086, 0x1091, 0x109c, 0x10a7, 
    0x10b2, 0x10bd, 0x10c8, 0x10d3, 0x10de, 0x10e9, 0x10f5, 0x1100, 
    0x110b, 0x1116, 0x1121, 0x112c, 0x1138, 0x1143, 0x114e, 0x1159, 
    0x1164, 0x116f, 0x117b, 0x1186, 0x1191, 0x119c, 0x11a7, 0x11b3, 
    0x11be, 0x11c9, 0x11d4, 0x11e0, 0x11eb, 0x11f6, 0x1201, 0x120d, 
    0x1218, 0x1223, 0x122f, 0x123a, 0x1245, 0x1251, 0x125c, 0x1267, 
    0x1272, 0x127e, 0x1289, 0x1294, 0x12a0, 0x12ab, 0x12b7, 0x12c2, 
    0x12cd, 0x12d9, 0x12e4, 0x12ef, 0x12fb, 0x1306, 0x1312, 0x131d, 
    0x1328, 0x1334, 0x133f, 0x134b, 0x1356, 0x1362, 0x136d, 0x1379, 
    0x1384, 0x1390, 0x139b, 0x13a7, 0x13b2, 0x13be, 0x13c9, 0x13d5, 
    0x13e0, 0x13ec, 0x13f7, 0x1403, 0x140e, 0x141a, 0x1425, 0x1431, 
    0x143d, 0x1448, 0x1454, 0x145f, 0x146b, 0x1477, 0x1482, 0x148e, 
    0x149a, 0x14a5, 0x14b1, 0x14bc, 0x14c8, 0x14d4, 0x14df, 0x14eb, 
    0x14f7, 0x1503, 0x150e, 0x151a, 0x1526, 0x1532, 0x153d, 0x1549, 
    0x1555, 0x1561, 0x156c, 0x1578, 0x1584, 0x1590, 0x159b, 0x15a7, 
    0x15b3, 0x15bf, 0x15cb, 0x15d7, 0x15e2, 0x15ee, 0x15fa, 0x1606, 
    0x1612, 0x161e, 0x162a, 0x1636, 0x1642, 0x164e, 0x1659, 0x1665, 
    0x1671, 0x167d, 0x1689, 0x1695, 0x16a1, 0x16ad, 0x16b9, 0x16c5, 
    0x16d1, 0x16dd, 0x16e9, 0x16f5, 0x1701, 0x170d, 0x171a, 0x1726, 
    0x1732, 0x173e, 0x174a, 0x1756, 0x1762, 0x176e, 0x177a, 0x1787, 
    0x1793, 0x179f, 0x17ab, 0x17b7, 0x17c4, 0x17d0, 0x17dc, 0x17e8, 
    0x17f4, 0x1801, 0x180d, 0x1819, 0x1825, 0x1832, 0x183e, 0x184a, 
    0x1857, 0x1863, 0x186f, 0x187c, 0x1888, 0x1894, 0x18a1, 0x18ad, 
    0x18b9, 0x18c6, 0x18d2, 0x18df, 0x18eb, 0x18f8, 0x1904, 0x1910, 
    0x191d, 0x1929, 0x1936, 0x1942, 0x194f, 0x195c, 0x1968, 0x1975, 
    0x1981, 0x198e, 0x199a, 0x19a7, 0x19b4, 0x19c0, 0x19cd, 0x19d9, 
    0x19e6, 0x19f3, 0x1a00, 0x1a0c, 0x1a19, 0x1a26, 0x1a32, 0x1a3f, 
    0x1a4c, 0x1a58, 0x1a65, 0x1a72, 0x1a7f, 0x1a8c, 0x1a98, 0x1aa5, 
    0x1ab2, 0x1abf, 0x1acc, 0x1ad9, 0x1ae6, 0x1af3, 0x1aff, 0x1b0c, 
    0x1b19, 0x1b26, 0x1b33, 0x1b40, 0x1b4d, 0x1b5a, 0x1b67, 0x1b74, 
    0x1b81, 0x1b8e, 0x1b9b, 0x1ba8, 0x1bb6, 0x1bc3, 0x1bd0, 0x1bdd, 
    0x1bea, 0x1bf7, 0x1c04, 0x1c12, 0x1c1f, 0x1c2c, 0x1c39, 0x1c47, 
    0x1c54, 0x1c61, 0x1c6e, 0x1c7c, 0x1c89, 0x1c96, 0x1ca4, 0x1cb1, 
    0x1cbe, 0x1ccc, 0x1cd9, 0x1ce7, 0x1cf4, 0x1d02, 0x1d0f, 0x1d1c, 
    0x1d2a, 0x1d37, 0x1d45, 0x1d53, 0x1d60, 0x1d6e, 0x1d7b, 0x1d89, 
    0x1d96, 0x1da4, 0x1db2, 0x1dbf, 0x1dcd, 0x1ddb, 0x1de8, 0x1df6, 
    0x1e04, 0x1e12, 0x1e1f, 0x1e2d, 0x1e3b, 0x1e49, 0x1e57, 0x1e65, 
    0x1e72, 0x1e80, 0x1e8e, 0x1e9c, 0x1eaa, 0x1eb8, 0x1ec6, 0x1ed4, 
    0x1ee2, 0x1ef0, 0x1efe, 0x1f0c, 0x1f1a, 0x1f29, 0x1f37, 0x1f45, 
    0x1f53, 0x1f61, 0x1f6f, 0x1f7d, 0x1f8c, 0x1f9a, 0x1fa8, 0x1fb6, 
    0x1fc5, 0x1fd3, 0x1fe2, 0x1ff0, 0x1ffe, 0x200d, 0x201b, 0x202a, 
    0x2038, 0x2047, 0x2055, 0x2064, 0x2072, 0x2081, 0x208f, 0x209e, 
    0x20ad, 0x20bb, 0x20ca, 0x20d9, 0x20e7, 0x20f6, 0x2105, 0x2114, 
    0x2122, 0x2131, 0x2140, 0x214f, 0x215e, 0x216d, 0x217c, 0x218b, 
    0x219a, 0x21a9, 0x21b8, 0x21c7, 0x21d6, 0x21e5, 0x21f4, 0x2204, 
    0x2213, 0x2222, 0x2231, 0x2240, 0x2250, 0x225f, 0x226e, 0x227e, 
    0x228d, 0x229c, 0x22ac, 0x22bb, 0x22cb, 0x22da, 0x22ea, 0x22f9, 
    0x2309, 0x2319, 0x2328, 0x2338, 0x2348, 0x2357, 0x2367, 0x2377, 
    0x2387, 0x2397, 0x23a7, 0x23b6, 0x23c6, 0x23d6, 0x23e6, 0x23f6, 
    0x2406, 0x2417, 0x2427, 0x2437, 0x2447, 0x2457, 0x2467, 0x2478, 
    0x2488, 0x2498, 0x24a9, 0x24b9, 0x24c9, 0x24da, 0x24ea, 0x24fb, 
    0x250c, 0x251c, 0x252d, 0x253e, 0x254e, 0x255f, 0x2570, 0x2581, 
    0x2591, 0x25a2, 0x25b3, 0x25c4, 0x25d5, 0x25e6, 0x25f7, 0x2608, 
    0x2619, 0x262a, 0x263c, 0x264d, 0x265e, 0x2670, 0x2681, 0x2692, 
    0x26a4, 0x26b5, 0x26c7, 0x26d8, 0x26ea, 0x26fc, 0x270d, 0x271f, 
    0x2731, 0x2743, 0x2755, 0x2767, 0x2779, 0x278b, 0x279d, 0x27af, 
    0x27c1, 0x27d3, 0x27e5, 0x27f8, 0x280a, 0x281c, 0x282f, 0x2841, 
    0x2854, 0x2866, 0x2879, 0x288c, 0x289f, 0x28b1, 0x28c4, 0x28d7, 
    0x28ea, 0x28fd, 0x2910, 0x2923, 0x2936, 0x2949, 0x295d, 0x2970, 
    0x2984, 0x2997, 0x29ab, 0x29be, 0x29d2, 0x29e5, 0x29f9, 0x2a0d, 
    0x2a21, 0x2a35, 0x2a49, 0x2a5d, 0x2a71, 0x2a85, 0x2a9a, 0x2aae, 
    0x2ac2, 0x2ad7, 0x2aeb, 0x2b00, 0x2b15, 0x2b29, 0x2b3e, 0x2b53, 
    0x2b68, 0x2b7d, 0x2b93, 0x2ba8, 0x2bbd, 0x2bd2, 0x2be8, 0x2bfd, 
    0x2c13, 0x2c29, 0x2c3f, 0x2c55, 0x2c6b, 0x2c81, 0x2c97, 0x2cad, 
    0x2cc3, 0x2cda, 0x2cf0, 0x2d07, 0x2d1e, 0x2d35, 0x2d4c, 0x2d63, 
    0x2d7a, 0x2d91, 0x2da8, 0x2dc0, 0x2dd7, 0x2def, 0x2e07, 0x2e1f, 
    0x2e37, 0x2e4f, 0x2e67, 0x2e80, 0x2e98, 0x2eb1, 0x2eca, 0x2ee3, 
    0x2efc, 0x2f15, 0x2f2e, 0x2f48, 0x2f61, 0x2f7b, 0x2f95, 0x2faf, 
    0x2fc9, 0x2fe4, 0x2ffe, 0x3019, 0x3034, 0x304f, 0x306a, 0x3085, 
    0x30a1, 0x30bc, 0x30d8, 0x30f4, 0x3111, 0x312d, 0x314a, 0x3167, 
    0x3184, 0x31a2, 0x31bf, 0x31dd, 0x31fb, 0x3219, 0x3238, 0x3257, 
    0x3276, 0x3295, 0x32b5, 0x32d5, 0x32f5, 0x3316, 0x3337, 0x3358, 
    0x3379, 0x339b, 0x33bd, 0x33e0, 0x3403, 0x3426, 0x344a, 0x346e, 
    0x3492, 0x34b8, 0x34dd, 0x3503, 0x3529, 0x3550, 0x3578, 0x35a0, 
    0x35c9, 0x35f2, 0x361c, 0x3647, 0x3673, 0x369f, 0x36cc, 0x36fa, 
    0x3729, 0x3759, 0x3789, 0x37bb, 0x37ef, 0x3823, 0x3859, 0x3890, 
    0x38c9, 0x3904, 0x3941, 0x3980, 0x39c1, 0x3a05, 0x3a4d, 0x3a98, 
    0x3ae7, 0x3b3b, 0x3b96, 0x3bf8, 0x3c65, 0x3ce1, 0x3d73, 0x3e32, 
    0x3fff
};
#else
#if ML_FIXED_RADIX == 12
static short arcsinLUT[] = { 
    0x0, 0x0, 0x1, 0x1, 0x2, 0x3, 0x3, 0x4, 
    0x5, 0x5, 0x6, 0x7, 0x7, 0x8, 0x8, 0x9, 
    0xa, 0xa, 0xb, 0xc, 0xc, 0xd, 0xe, 0xe, 
    0xf, 0xf, 0x10, 0x11, 0x11, 0x12, 0x13, 0x13, 
    0x14, 0x15, 0x15, 0x16, 0x16, 0x17, 0x18, 0x18, 
    0x19, 0x1a, 0x1a, 0x1b, 0x1c, 0x1c, 0x1d, 0x1d, 
    0x1e, 0x1f, 0x1f, 0x20, 0x21, 0x21, 0x22, 0x23, 
    0x23, 0x24, 0x24, 0x25, 0x26, 0x26, 0x27, 0x28, 
    0x28, 0x29, 0x2a, 0x2a, 0x2b, 0x2b, 0x2c, 0x2d, 
    0x2d, 0x2e, 0x2f, 0x2f, 0x30, 0x31, 0x31, 0x32, 
    0x32, 0x33, 0x34, 0x34, 0x35, 0x36, 0x36, 0x37, 
    0x38, 0x38, 0x39, 0x3a, 0x3a, 0x3b, 0x3b, 0x3c, 
    0x3d, 0x3d, 0x3e, 0x3f, 0x3f, 0x40, 0x41, 0x41, 
    0x42, 0x42, 0x43, 0x44, 0x44, 0x45, 0x46, 0x46, 
    0x47, 0x48, 0x48, 0x49, 0x49, 0x4a, 0x4b, 0x4b, 
    0x4c, 0x4d, 0x4d, 0x4e, 0x4f, 0x4f, 0x50, 0x51, 
    0x51, 0x52, 0x52, 0x53, 0x54, 0x54, 0x55, 0x56, 
    0x56, 0x57, 0x58, 0x58, 0x59, 0x5a, 0x5a, 0x5b, 
    0x5b, 0x5c, 0x5d, 0x5d, 0x5e, 0x5f, 0x5f, 0x60, 
    0x61, 0x61, 0x62, 0x63, 0x63, 0x64, 0x64, 0x65, 
    0x66, 0x66, 0x67, 0x68, 0x68, 0x69, 0x6a, 0x6a, 
    0x6b, 0x6c, 0x6c, 0x6d, 0x6e, 0x6e, 0x6f, 0x6f, 
    0x70, 0x71, 0x71, 0x72, 0x73, 0x73, 0x74, 0x75, 
    0x75, 0x76, 0x77, 0x77, 0x78, 0x79, 0x79, 0x7a, 
    0x7a, 0x7b, 0x7c, 0x7c, 0x7d, 0x7e, 0x7e, 0x7f, 
    0x80, 0x80, 0x81, 0x82, 0x82, 0x83, 0x84, 0x84, 
    0x85, 0x85, 0x86, 0x87, 0x87, 0x88, 0x89, 0x89, 
    0x8a, 0x8b, 0x8b, 0x8c, 0x8d, 0x8d, 0x8e, 0x8f, 
    0x8f, 0x90, 0x91, 0x91, 0x92, 0x93, 0x93, 0x94, 
    0x94, 0x95, 0x96, 0x96, 0x97, 0x98, 0x98, 0x99, 
    0x9a, 0x9a, 0x9b, 0x9c, 0x9c, 0x9d, 0x9e, 0x9e, 
    0x9f, 0xa0, 0xa0, 0xa1, 0xa2, 0xa2, 0xa3, 0xa4, 
    0xa4, 0xa5, 0xa6, 0xa6, 0xa7, 0xa8, 0xa8, 0xa9, 
    0xa9, 0xaa, 0xab, 0xab, 0xac, 0xad, 0xad, 0xae, 
    0xaf, 0xaf, 0xb0, 0xb1, 0xb1, 0xb2, 0xb3, 0xb3, 
    0xb4, 0xb5, 0xb5, 0xb6, 0xb7, 0xb7, 0xb8, 0xb9, 
    0xb9, 0xba, 0xbb, 0xbb, 0xbc, 0xbd, 0xbd, 0xbe, 
    0xbf, 0xbf, 0xc0, 0xc1, 0xc1, 0xc2, 0xc3, 0xc3, 
    0xc4, 0xc5, 0xc5, 0xc6, 0xc7, 0xc7, 0xc8, 0xc9, 
    0xc9, 0xca, 0xcb, 0xcb, 0xcc, 0xcd, 0xcd, 0xce, 
    0xcf, 0xcf, 0xd0, 0xd1, 0xd1, 0xd2, 0xd3, 0xd3, 
    0xd4, 0xd5, 0xd5, 0xd6, 0xd7, 0xd7, 0xd8, 0xd9, 
    0xd9, 0xda, 0xdb, 0xdb, 0xdc, 0xdd, 0xdd, 0xde, 
    0xdf, 0xe0, 0xe0, 0xe1, 0xe2, 0xe2, 0xe3, 0xe4, 
    0xe4, 0xe5, 0xe6, 0xe6, 0xe7, 0xe8, 0xe8, 0xe9, 
    0xea, 0xea, 0xeb, 0xec, 0xec, 0xed, 0xee, 0xee, 
    0xef, 0xf0, 0xf1, 0xf1, 0xf2, 0xf3, 0xf3, 0xf4, 
    0xf5, 0xf5, 0xf6, 0xf7, 0xf7, 0xf8, 0xf9, 0xf9, 
    0xfa, 0xfb, 0xfb, 0xfc, 0xfd, 0xfe, 0xfe, 0xff, 
    0x100, 0x100, 0x101, 0x102, 0x102, 0x103, 0x104, 0x104, 
    0x105, 0x106, 0x106, 0x107, 0x108, 0x109, 0x109, 0x10a, 
    0x10b, 0x10b, 0x10c, 0x10d, 0x10d, 0x10e, 0x10f, 0x110, 
    0x110, 0x111, 0x112, 0x112, 0x113, 0x114, 0x114, 0x115, 
    0x116, 0x116, 0x117, 0x118, 0x119, 0x119, 0x11a, 0x11b, 
    0x11b, 0x11c, 0x11d, 0x11e, 0x11e, 0x11f, 0x120, 0x120, 
    0x121, 0x122, 0x122, 0x123, 0x124, 0x125, 0x125, 0x126, 
    0x127, 0x127, 0x128, 0x129, 0x12a, 0x12a, 0x12b, 0x12c, 
    0x12c, 0x12d, 0x12e, 0x12e, 0x12f, 0x130, 0x131, 0x131, 
    0x132, 0x133, 0x133, 0x134, 0x135, 0x136, 0x136, 0x137, 
    0x138, 0x139, 0x139, 0x13a, 0x13b, 0x13b, 0x13c, 0x13d, 
    0x13e, 0x13e, 0x13f, 0x140, 0x140, 0x141, 0x142, 0x143, 
    0x143, 0x144, 0x145, 0x145, 0x146, 0x147, 0x148, 0x148, 
    0x149, 0x14a, 0x14b, 0x14b, 0x14c, 0x14d, 0x14d, 0x14e, 
    0x14f, 0x150, 0x150, 0x151, 0x152, 0x153, 0x153, 0x154, 
    0x155, 0x156, 0x156, 0x157, 0x158, 0x159, 0x159, 0x15a, 
    0x15b, 0x15b, 0x15c, 0x15d, 0x15e, 0x15e, 0x15f, 0x160, 
    0x161, 0x161, 0x162, 0x163, 0x164, 0x164, 0x165, 0x166, 
    0x167, 0x167, 0x168, 0x169, 0x16a, 0x16a, 0x16b, 0x16c, 
    0x16d, 0x16d, 0x16e, 0x16f, 0x170, 0x170, 0x171, 0x172, 
    0x173, 0x173, 0x174, 0x175, 0x176, 0x176, 0x177, 0x178, 
    0x179, 0x179, 0x17a, 0x17b, 0x17c, 0x17d, 0x17d, 0x17e, 
    0x17f, 0x180, 0x180, 0x181, 0x182, 0x183, 0x183, 0x184, 
    0x185, 0x186, 0x186, 0x187, 0x188, 0x189, 0x18a, 0x18a, 
    0x18b, 0x18c, 0x18d, 0x18d, 0x18e, 0x18f, 0x190, 0x191, 
    0x191, 0x192, 0x193, 0x194, 0x194, 0x195, 0x196, 0x197, 
    0x198, 0x198, 0x199, 0x19a, 0x19b, 0x19c, 0x19c, 0x19d, 
    0x19e, 0x19f, 0x1a0, 0x1a0, 0x1a1, 0x1a2, 0x1a3, 0x1a3, 
    0x1a4, 0x1a5, 0x1a6, 0x1a7, 0x1a7, 0x1a8, 0x1a9, 0x1aa, 
    0x1ab, 0x1ab, 0x1ac, 0x1ad, 0x1ae, 0x1af, 0x1af, 0x1b0, 
    0x1b1, 0x1b2, 0x1b3, 0x1b4, 0x1b4, 0x1b5, 0x1b6, 0x1b7, 
    0x1b8, 0x1b8, 0x1b9, 0x1ba, 0x1bb, 0x1bc, 0x1bd, 0x1bd, 
    0x1be, 0x1bf, 0x1c0, 0x1c1, 0x1c1, 0x1c2, 0x1c3, 0x1c4, 
    0x1c5, 0x1c6, 0x1c6, 0x1c7, 0x1c8, 0x1c9, 0x1ca, 0x1cb, 
    0x1cb, 0x1cc, 0x1cd, 0x1ce, 0x1cf, 0x1d0, 0x1d0, 0x1d1, 
    0x1d2, 0x1d3, 0x1d4, 0x1d5, 0x1d6, 0x1d6, 0x1d7, 0x1d8, 
    0x1d9, 0x1da, 0x1db, 0x1db, 0x1dc, 0x1dd, 0x1de, 0x1df, 
    0x1e0, 0x1e1, 0x1e1, 0x1e2, 0x1e3, 0x1e4, 0x1e5, 0x1e6, 
    0x1e7, 0x1e8, 0x1e8, 0x1e9, 0x1ea, 0x1eb, 0x1ec, 0x1ed, 
    0x1ee, 0x1ef, 0x1ef, 0x1f0, 0x1f1, 0x1f2, 0x1f3, 0x1f4, 
    0x1f5, 0x1f6, 0x1f6, 0x1f7, 0x1f8, 0x1f9, 0x1fa, 0x1fb, 
    0x1fc, 0x1fd, 0x1fe, 0x1ff, 0x1ff, 0x200, 0x201, 0x202, 
    0x203, 0x204, 0x205, 0x206, 0x207, 0x208, 0x208, 0x209, 
    0x20a, 0x20b, 0x20c, 0x20d, 0x20e, 0x20f, 0x210, 0x211, 
    0x212, 0x213, 0x214, 0x214, 0x215, 0x216, 0x217, 0x218, 
    0x219, 0x21a, 0x21b, 0x21c, 0x21d, 0x21e, 0x21f, 0x220, 
    0x221, 0x222, 0x223, 0x224, 0x225, 0x225, 0x226, 0x227, 
    0x228, 0x229, 0x22a, 0x22b, 0x22c, 0x22d, 0x22e, 0x22f, 
    0x230, 0x231, 0x232, 0x233, 0x234, 0x235, 0x236, 0x237, 
    0x238, 0x239, 0x23a, 0x23b, 0x23c, 0x23d, 0x23e, 0x23f, 
    0x240, 0x241, 0x242, 0x243, 0x244, 0x245, 0x246, 0x247, 
    0x248, 0x249, 0x24a, 0x24b, 0x24c, 0x24d, 0x24e, 0x24f, 
    0x250, 0x251, 0x252, 0x253, 0x254, 0x255, 0x257, 0x258, 
    0x259, 0x25a, 0x25b, 0x25c, 0x25d, 0x25e, 0x25f, 0x260, 
    0x261, 0x262, 0x263, 0x264, 0x265, 0x267, 0x268, 0x269, 
    0x26a, 0x26b, 0x26c, 0x26d, 0x26e, 0x26f, 0x270, 0x271, 
    0x273, 0x274, 0x275, 0x276, 0x277, 0x278, 0x279, 0x27a, 
    0x27c, 0x27d, 0x27e, 0x27f, 0x280, 0x281, 0x282, 0x284, 
    0x285, 0x286, 0x287, 0x288, 0x289, 0x28b, 0x28c, 0x28d, 
    0x28e, 0x28f, 0x291, 0x292, 0x293, 0x294, 0x295, 0x297, 
    0x298, 0x299, 0x29a, 0x29b, 0x29d, 0x29e, 0x29f, 0x2a0, 
    0x2a2, 0x2a3, 0x2a4, 0x2a5, 0x2a7, 0x2a8, 0x2a9, 0x2aa, 
    0x2ac, 0x2ad, 0x2ae, 0x2b0, 0x2b1, 0x2b2, 0x2b3, 0x2b5, 
    0x2b6, 0x2b7, 0x2b9, 0x2ba, 0x2bb, 0x2bd, 0x2be, 0x2bf, 
    0x2c1, 0x2c2, 0x2c3, 0x2c5, 0x2c6, 0x2c8, 0x2c9, 0x2ca, 
    0x2cc, 0x2cd, 0x2cf, 0x2d0, 0x2d1, 0x2d3, 0x2d4, 0x2d6, 
    0x2d7, 0x2d9, 0x2da, 0x2dc, 0x2dd, 0x2de, 0x2e0, 0x2e1, 
    0x2e3, 0x2e4, 0x2e6, 0x2e8, 0x2e9, 0x2eb, 0x2ec, 0x2ee, 
    0x2ef, 0x2f1, 0x2f2, 0x2f4, 0x2f6, 0x2f7, 0x2f9, 0x2fa, 
    0x2fc, 0x2fe, 0x2ff, 0x301, 0x303, 0x304, 0x306, 0x308, 
    0x30a, 0x30b, 0x30d, 0x30f, 0x311, 0x312, 0x314, 0x316, 
    0x318, 0x31a, 0x31b, 0x31d, 0x31f, 0x321, 0x323, 0x325, 
    0x327, 0x329, 0x32b, 0x32d, 0x32f, 0x331, 0x333, 0x335, 
    0x337, 0x339, 0x33b, 0x33e, 0x340, 0x342, 0x344, 0x346, 
    0x349, 0x34b, 0x34d, 0x350, 0x352, 0x355, 0x357, 0x35a, 
    0x35c, 0x35f, 0x361, 0x364, 0x367, 0x369, 0x36c, 0x36f, 
    0x372, 0x375, 0x378, 0x37b, 0x37e, 0x382, 0x385, 0x389, 
    0x38c, 0x390, 0x394, 0x398, 0x39c, 0x3a0, 0x3a4, 0x3a9, 
    0x3ae, 0x3b3, 0x3b9, 0x3bf, 0x3c6, 0x3ce, 0x3d7, 0x3e3, 
    0x3ff
};
#endif
#endif

// ... to here.
#endif  /* WRITE_LUT */

#if (ML_FIXED_RADIX == 16)
// 10 bits as .1111111111000000
//  6 bits as .0000000000111111
#define INDEX_SHIFT 6
#define INDEX_MASK (0x0000003ff << INDEX_SHIFT)
#define REMDR_MASK (0x00000003f)
#define LUT_LENGTH 1024 /* 1 << 10 */

#else /* (ML_FIXED_RADIX == 16) */

#if (ML_FIXED_RADIX == 12)
// 10 bits as .111111111100
//  2 bits as .000000000011
#define INDEX_SHIFT 2
#define INDEX_MASK (0x000003ff << INDEX_SHIFT)
#define REMDR_MASK (0x00000003)
#define LUT_LENGTH 1024 /* 1 << 10 */
#endif /* (ML_FIXED_RADIX == 12) */

#endif /* (ML_FIXED_RADIX == 16) */

#define REMDR_SHIFT (ML_FIXED_RADIX - INDEX_SHIFT)


static void
asineTableIndex( MlScalar x, unsigned long &index, unsigned long &remdr, unsigned long &sign )
{
    long opX = mlScalarGetValue( x );
#if ML_FIXED_CHECK_UNINITIALIZED
    MLE_ASSERT(opX != 0xdeadbeef);
#endif
    sign = (opX < 0);
    unsigned long op = (sign) ? -opX : opX;

    if (op >= (1<<ML_FIXED_RADIX)) {
        index = LUT_LENGTH;
        remdr = 0;
        return;
    }

    index = (op & INDEX_MASK) >> INDEX_SHIFT;
    remdr = (op & REMDR_MASK);

    return;    
}

// z = asin(x);
MlScalar
FixedAsin( const MlScalar x ) 
{ 
    unsigned long index, remdr, sign;

    // Note that asinf() returns a NaN for out-of-range arguments,
    // so make a similar assertion.  If someone\'s sine computation 
    // is off by a little, they\'ll find out.  In optimized mode
    // they\'ll just get a reasonable value.

    if (x >= ML_SCALAR_ONE) {
        MLE_ASSERT(x <= ML_SCALAR_ONE);
        return ML_ANGLE_PI_HALF;
    }
    else if (x <= -ML_SCALAR_ONE) {
        MLE_ASSERT(x >= -ML_SCALAR_ONE);
        return -ML_ANGLE_PI_HALF;
    }

    asineTableIndex( x, index, remdr, sign );
    long angle = FixedShortTableInterp( arcsinLUT, index, remdr, sign, REMDR_SHIFT );

    return mlScalarSetValue( angle );    
} 


// z = acos(x);
MlScalar
FixedAcos( const MlScalar x ) 
{ 
    MlScalar as = FixedAsin( x );
    return ML_ANGLE_PI_HALF - as;
} 


//////////////////////////////////////////////////////////////////////////
//  Write out the lookup table for use in fixed point arcsine computations.
//////////////////////////////////////////////////////////////////////////

#ifdef WRITE_LUT

#include <stdio.h>

// Make sure we do it with the fixed point flag on so that 
// mlScalarGetValue() returns a long.

#undef ML_FIXED_POINT
#define ML_FIXED_POINT 1

#include <math.h>

void writeLUT( int length, int shift )
{
    long *lut = new long[length + 1];
    int i;
    float x;
    MlScalar scalar;
    
    for (i=0; i<=length; i++) {
        x = asinf((float)i / (float) length);
        scalar = mlRadiansToAngle(mlFloatToScalar(x));
        lut[i] = mlScalarGetValue(scalar);
    }

    printf( "static short arcsinLUT[] = { \n\t" );
    for (i=0; i<length; i++) {
        printf("0x%lx, ", lut[i] >> shift);
        if (7 == (i % 8)) {
            printf("\n\t");
        }
    }
    printf("0x%lx", lut[length] >> shift);
    printf( "\n};\n" );

    return;
}

int main ()
{
    printf("#if ML_FIXED_RADIX == %d\n", 16);
    writeLUT( 1024, 16-16 );
    printf("#else\n#if ML_FIXED_RADIX == %d\n", 12);
    writeLUT( 1024, 16-12 );
    printf("#endif\n#endif\n");    

    return 0;
}

#endif

//////////////////////////////////////////////////////////////////////////
//  Test the arcsine and arccosine function
//////////////////////////////////////////////////////////////////////////

#ifdef TEST_ARCSINE_ARCCOSINE

#undef ML_FIXED_POINT
#define ML_FIXED_POINT 1

#undef ML_MATH_DEBUG
#define ML_MATH_DEBUG 1

#include <stdio.h>
#include <math.h>

int main ()
{
    int i, N;
    float xx, x, sx, cx, fsx, fcx;
    MlScalar fx, tmp;
    float ec, es;
    float errs, errc;
    float xerrs, xerrc;

    N = 100;
    errs = 0.0f;
    errc = 0.0f;
    printf("Testing %d numbers\n", N);
//  printf(" asin/acos  scalar()   asin(x)    mlAsin(x) acos(x)   mlAcos(x) errAsin   errACos\n");

    // Might also want to test that, for i outside the legal range of
    // [-N..N], the arc sine function gets the right error assertion.
    
    for (i=-N; i<=N; i++) {
        x = i / (float)N;
        fx = mlFloatToScalar(x);
        xx = mlScalarToFloat(fx);
        sx = asinf(xx) / (2.0f * M_PI); // in Magic Lantern angles
        cx = acosf(xx) / (2.0f * M_PI); // in Magic Lantern angles
        tmp = mlAsin(fx);
        fsx = mlScalarToFloat(tmp);
        tmp = mlAcos(fx);
        fcx = mlScalarToFloat(tmp);
        es = fabsf(sx-fsx);
        ec = fabsf(cx-fcx);
//        printf("%9.7f %9.7f %9.7f %9.7f %9.7f %9.7f %9.7f %9.7f\n", 
//               x, xx,
//               sx, fsx, cx, fcx, es, ec);
        if (es > errs) {
            errs = es;
            xerrs = x;
        }
        if (ec > errc) {
            errc = ec;
            xerrc = x;
        }
    }

    if (errs != 0.0f || errc != 0.0f) {
        printf("Max arcsin([0..2PI]) error of %f at %f.\n", errs, xerrs);
        printf("Max arccos([0..2PI]) error of %f at %f.\n", errc, xerrc);
    }
    else {
        printf("Max arcsin([0..2PI]) error == 0.0f\n");
    }


    return 0;
}

#endif

#endif
