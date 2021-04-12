/*
 * This file is part of the TrinityCore Project. See AUTHORS file for Copyright information
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include "scriptPCH.h"
#include "Utilities/EventMap.h"
#include <array>

enum FireworksShowTypeObjects
{
    FIREWORK_SHOW_TYPE_1_RED        = 180703,
    FIREWORK_SHOW_TYPE_2_RED        = 180704,
    FIREWORK_SHOW_TYPE_1_RED_BIG    = 180707,
    FIREWORK_SHOW_TYPE_2_RED_BIG    = 180708,
    FIREWORK_SHOW_TYPE_1_BLUE       = 180720,
    FIREWORK_SHOW_TYPE_2_BLUE       = 180721,
    FIREWORK_SHOW_TYPE_1_BLUE_BIG   = 180722,
    FIREWORK_SHOW_TYPE_2_BLUE_BIG   = 180723,
    FIREWORK_SHOW_TYPE_1_GREEN      = 180724,
    FIREWORK_SHOW_TYPE_2_GREEN_BIG  = 180725,
    FIREWORK_SHOW_TYPE_1_GREEN_BIG  = 180726,
    FIREWORK_SHOW_TYPE_2_GREEN      = 180727,
    FIREWORK_SHOW_TYPE_1_WHITE      = 180728,
    FIREWORK_SHOW_TYPE_1_WHITE_BIG  = 180729,
    FIREWORK_SHOW_TYPE_2_WHITE      = 180730,
    FIREWORK_SHOW_TYPE_2_WHITE_BIG  = 180731,
    FIREWORK_SHOW_TYPE_1_YELLOW     = 180736,
    FIREWORK_SHOW_TYPE_1_YELLOW_BIG = 180737,
    FIREWORK_SHOW_TYPE_2_YELLOW     = 180738,
    FIREWORK_SHOW_TYPE_2_YELLOW_BIG = 180739,
    FIREWORK_SHOW_TYPE_2_PURPLE     = 180740,
    FIREWORK_SHOW_TYPE_1_PURPLE_BIG = 180741,
    FIREWORK_SHOW_TYPE_2_PURPLE_BIG = 180733
};

enum FireworksMisc
{
    SOUND_CHEER_1        = 8574,
    SOUND_CHEER_2        = 8573,
    SOUND_CHEER_3        = 8572,
    SOUND_CHEER_4        = 8571,
    EVENT_CHEER          = 1,
    EVENT_FIRE           = 2,
    GAME_EVENT_FIREWORKS = 6
};

enum FireworksZones
{
    STRANGLETHORN_VALE = 33,   // Booty bay
    ORGRIMMAR          = 1637,
    DUROTAR            = 14,   // Orgrimmar
    UNDERCITY          = 1497,
    TIRISFAL_GLADES    = 85,   // Undercity
    TELDRASSIL         = 141,  // Darnassus
    THUNDERBLUFF       = 1638,
    DUN_MOROGH         = 1,    // Ironforge
    IRONFORGE          = 1537,
    STORMWIND          = 1519
};

static const std::vector<Position> BootyBayPos =
{
    { -14358.03f, 515.058f, 34.2664f,   3.68265f   },
    { -14357.49f, 490.8445f, 39.47329f, 0.9773831f },
    { -14355.49f, 518.5656f, 35.36923f, 4.76475f   },
    { -14353.66f, 485.8341f, 36.86639f, 4.886924f  },
    { -14376.54f, 487.5282f, 44.47044f, 5.899214f  },
    { -14376.66f, 516.6852f, 38.5385f,  2.199115f  },
    { -14382.42f, 516.2576f, 37.59617f, 5.846854f  },
    { -14389.55f, 485.7437f, 36.32653f, 6.0912f    },
    { -14376.76f, 507.9842f, 59.56532f, 0.9773831f },
    { -14358.97f, 502.0223f, 43.82631f, 2.199115f  },
    { -14370.77f, 487.4859f, 45.46445f, 4.886924f  },
    { -14379.15f, 507.237f,  43.95641f, 6.0912f    },
    { -14363.28f, 506.7344f, 41.27156f, 5.899214f  },
    { -14374.43f, 496.0701f, 31.31265f, 4.76475f   },
    { -14360.71f, 493.6036f, 32.06157f, 5.846854f  },
    { -14354.37f, 491.8791f, 39.83374f, 3.68265f   },
    { -14371.19f, 505.8404f, 28.75178f, 6.0912f    },
    { -14356.57f, 494.1887f, 39.58786f, 3.68265f   },
    { -14380.02f, 506.3313f, 59.75512f, 6.0912f    },
    { -14389.84f, 503.4612f, 37.37088f, 5.899214f  },
    { -14353.64f, 485.4063f, 34.11704f, 4.76475f   },
    { -14359.63f, 522.2571f, 31.2866f,  2.199115f  },
    { -14374.91f, 491.508f,  40.34925f, 4.886924f  },
    { -14351.33f, 506.1898f, 28.69684f, 5.846854f  },
    { -14378.1f,  473.5608f, 40.16786f, 0.9773831f }
};

static const std::vector<Position> StormwindPos =
{
    { -8823.592f,    470.316f,    179.2295f,   1.239183f  },
    { -8883.005f,    590.1927f,   163.1264f,   0.9773831f },
    { -8919.692f,    482.9097f,   185.6471f,   3.735006f  },
    { -8907.228f,    551.7864f,   188.68f,     4.729844f  },
    { -8979.651f,    639.3976f,   184.4983f,   3.961899f  },
    { -8878.851f,    583.1771f,   166.3018f,   3.700105f  },
    { -8937.466f,    517.0521f,   183.7207f,   3.68265f   },
    { -8919.247f,    562.2882f,   176.1023f,   3.630291f  },
    { -8866.37f,     576.0504f,   157.8798f,   3.47321f   },
    { -8957.122f,    517.7014f,   161.3226f,   3.630291f  },
    { -8957.857f,    521.934f,    158.9058f,   4.729844f  },
    { -8851.988f,    486.5625f,   179.6635f,   4.258607f  },
    { -8972.651f,    531.0799f,   176.6744f,   4.886924f  },
    { -8986.207f,    560.9792f,   179.1758f,   5.550147f  },
    { -8848.866f,    488.8281f,   184.9777f,   3.961899f  },
    { -8946.897f,    521.3976f,   193.4021f,   0.9424766f },
    { -8876.854f,    593.6771f,   171.0399f,   0.1396245f },
    { -8828.743f,    463.0382f,   195.7672f,   0.9424766f },
    { -8968.125f,    525.1285f,   181.9304f,   3.054327f  },
    { -8952.893f,    629.2743f,   188.2722f,   0.9424766f },
    { -8882.172f,    574.4219f,   181.7124f,   6.0912f    },
    { -8980.363f,    546.7934f,   180.4686f,   4.66003f   },
    { -8874.944f,    575.5f,      175.7746f,   0.9075702f },
    { -8945.109f,    496.3715f,   153.2825f,   6.073746f  },
    { -8953.094f,    513.5521f,   180.9165f,   3.735006f  },
    { -8955.02f,     623.7621f,   193.7679f,   0.9424766f },
    { -8977.524f,    644.9097f,   197.926f,    3.961899f  },
    { -8985.639f,    653.9809f,   200.0452f,   3.630291f  },
    { -8985.639f,    653.9809f,   200.0452f,   3.630291f  },
    { -8849.723f,    624.1337f,   144.0357f,   0.8552105f },
    { -8938.404f,    511.8854f,   179.5132f,   0.4712385f },
    { -8815.946f,    571.0833f,   166.8412f,   0.8552105f },
    { -8968.125f,    525.1285f,   180.6735f,   3.054327f  },
    { -8887.63f,     582.0261f,   180.219f,    3.787367f  },
    { -8962.538f,    541.4132f,   169.8063f,   0.6283169f },
    { -8854.854f,    503.4115f,   194.6336f,   3.630291f  },
    { -8810.004f,    589.0504f,   150.2928f,   0.8552105f },
    { -8921.13f,     570.2153f,   186.4456f,   3.857183f  },
    { -8957.076f,    538.8073f,   165.0997f,   0.5235979f },
    { -8954.139f,    507.5695f,   178.861f,    3.595379f  },
    { -8817.174f,    577.4948f,   152.5639f,   0.8552105f },
    { -8808.778f,    582.6389f,   158.5705f,   0.8552105f },
    { -8898.136f,    566.4236f,   186.5282f,   6.0912f    },
    { -8877.205f,    598.0347f,   164.5646f,   0.1396245f },
    { -8815.911f,    460.2049f,   179.4585f,   3.926996f  },
    { -8836.877f,    574.1649f,   168.0506f,   0.8552105f },
    { -8883.005f,    590.1927f,   157.0154f,   0.9773831f },
    { -8942.71f,     561.3316f,   198.328f,    3.630291f  },
    { -8949.616f,    617.007f,    197.4469f,   3.630291f  },
    { -8939.357f,    507.9288f,   155.7625f,   0.6457717f },
    { -8976.667f,    558.6233f,   170.7597f,   5.550147f  },
    { -8871.924f,    609.7327f,   151.6364f,   0.8552105f },
    { -8829.264f,    551.5052f,   137.5144f,   0.8552105f },
    { -8859.802f,    567.184f,    162.9909f,   3.47321f   },
    { -8864.504f,    604.0816f,   144.7161f,   0.8552105f },
    { -8854.042f,    616.0121f,   146.4188f,   0.8552105f },
    { -8839.778f,    576.8004f,   163.2873f,   0.8552105f },
    { -8863.049f,    497.7986f,   179.2041f,   3.926996f  },
    { -8951.743f,    611.4948f,   185.3027f,   3.630291f  },
    { -8976.063f,    535.0504f,   178.1283f,   4.66003f   },
    { -8937.466f,    517.0521f,   170.561f,    3.68265f   },
    { -8940.363f,    490.4288f,   180.8207f,   3.996807f  },
    { -8838.177f,    541.6476f,   168.6789f,   0.8552105f },
    { -8825.467f,    450.7708f,   196.6236f,   3.630291f  },
    { -8878.851f,    583.1771f,   165.5726f,   3.700105f  },
    { -8822.146f,    557.2292f,   147.8244f,   0.8552105f },
    { -8953.243f,    523.8958f,   158.0031f,   3.630291f  },
    { -8983.514f,    659.493f,    198.6248f,   3.630291f  },
    { -8939.941f,    499.6163f,   158.6714f,   3.944446f  },
    { -8925.567f,    542.2158f,   116.1619f,   6.0912f    },
    { -8964.125f,    634.6736f,   182.0301f,   0.6283169f },
    { -8930.696f,    491.8021f,   185.6471f,   3.944446f  },
    { -8882.172f,    574.4219f,   165.4764f,   6.0912f    },
    { -8943.316f,    516.0191f,   155.9438f,   5.846854f  },
    { -8871.973f,    589.2795f,   159.1132f,   0.4712385f },
    { -8883.328f,    579.6736f,   172.1912f,   0.6283169f },
    { -8961.998f,    640.1858f,   188.2798f,   0.6283169f },
    { -8912.467f,    506.625f,    175.9382f,   5.846854f  },
    { -8843.524f,    481.7865f,   179.664f,    0.9250238f },
    { -8964.986f,    535.2136f,   163.4313f,   4.886924f  },
    { -8833.341f,    484.1042f,   192.8578f,   0.6283169f },
    { -8861.382f,    574.7413f,   162.1575f,   3.47321f   },
    { -8973.627f,    631.7726f,   192.3904f,   0.6283169f },
    { -8878.851f,    583.1771f,   166.149f,    3.700105f  },
    { -8842.842f,    481.2031f,   204.4827f,   0.6283169f },
    { -8902.143f,    527.5035f,   187.1883f,   3.630291f  },
    { -8956.248f,    514.2257f,   161.3226f,   3.630291f  },
    { -8835.826f,    488.0764f,   179.2099f,   0.9250238f },
    { -8961.319f,    533.3333f,   162.5372f,   3.961899f  },
    { -8947.649f,    516.0955f,   163.2207f,   3.68265f   },
    { -8949.186f,    504.1337f,   180.9165f,   3.804818f  },
    { -8945.564f,    511.5156f,   164.3801f,   5.899214f  },
    { -8969.266f,    543.882f,    180.4686f,   4.66003f   },
    { -8874.156f,    586.6302f,   161.5547f,   0.9773831f },
    { -8919.748f,    552.2986f,   176.0453f,   3.996807f  },
    { -8971.5f,      637.2847f,   197.926f,    0.6283169f },
    { -8965.389f,    525.8906f,   170.2664f,   2.199115f  },
    { -8885.1768f,   584.675781f, 141.623886f, 0.62527f   },
    { -8880.427734f, 576.678406f, 141.62886f,  0.69819f   },
    { -8873.7005f,   570.2418f,   139.33889f,  0.762973f  },
    { -8888.692383f, 571.265015f, 120.36886f,  0.601966f  },
    { -8870.9571f,   575.9952f,   120.811226f, 0.880780f  },
    { -8875.3905f,   582.87028f,  120.81226f,  0.76898f   },
    { -8887.0238f,   594.304871f, 120.81226f,  0.700139f  },
    { -8887.0238f,   594.3041f,   132.571243f, 5.30658f   },
    { -8874.3430f,   584.368164f, 131.409271f, 5.428242f  },
    { -8856.23049f,  573.789795f, 131.861237f, 5.707060f  },
    { -8881.462891f, 592.391418f, 118.883751f, 0.464518f  },
    { -8871.443359f, 582.234802f, 117.030724f, 0.562685f  },
    { -8884.809570f, 576.020081f, 110.489868f, 0.621592f  },
    { -8871.830078f, 585.984314f, 110.492371f, 0.696206f  },
    { -8871.830078f, 585.984314f, 119.252373f, 0.700133f  },
    { -8875.578125f, 563.403931f, 114.059372f, 4.521095f  },
    { -8896.128906f, 584.406311f, 117.437462f, 2.922810f  },
    { -8873.742188f, 599.873718f, 117.512787f, 3.001356f  },
    { -8885.817383f, 586.529175f, 108.614265f,  0.437024f  },
    { -8872.734375f, 573.338440f, 107.723770f,  1.831103f  }
};

static const std::vector<Position> OrgrimmarPos =
{
    { 1609.075f,    -4383.707f,     90.23414f,  0.3665176f  },
    { 1469.648f,    -4371.285f,    113.8313f,   6.073746f   },
    { 1391.792f,    -4371.f,       165.0406f,   3.630291f   },
    { 1405.918f,    -4504.896f,    123.1683f,   3.700105f   },
    { 1610.016f,    -4386.493f,    82.81187f,   3.909541f   },
    { 1523.767f,    -4385.934f,    100.7948f,   4.572764f   },
    { 1486.345f,    -4493.087f,    146.1718f,   0.1396245f  },
    { 1606.724f,    -4414.668f,    121.4687f,   5.550147f   },
    { 1647.043f,    -4402.644f,    121.7353f,   1.570796f   },
    { 1573.078f,    -4426.342f,    104.5087f,   5.550147f   },
    { 1600.927f,    -4367.731f,     87.9886f,   3.874631f   },
    { 1558.359f,    -4368.33f,     120.0258f,   4.363324f   },
    { 1377.49f,     -4298.74f,     136.4911f,   5.846854f   },
    { 1395.439f,    -4403.583f,    170.1769f,   3.68265f    },
    { 1394.175f,    -4390.438f,    166.5045f,   5.550147f   },
    { 1389.752f,    -4352.681f,    150.5359f,   3.228859f   },
    { 1471.724f,    -4393.083f,    129.966f,    3.159062f   },
    { 1586.208f,    -4334.78f,     104.248f,    2.617989f   },
    { 1590.582f,    -4338.588f,    110.6812f,   0.2094394f  },
    { 1601.163f,    -4367.491f,    105.1535f,   0.5410506f  },
    { 1493.476f,    -4448.524f,    142.9773f,   3.630291f   },
    { 1481.592f,    -4421.177f,    156.4658f,   0.1396245f  },
    { 1382.604f,    -4319.927f,    143.5185f,   3.298687f   },
    { 1647.483f,    -4404.724f,    113.3714f,   2.617989f   },
    { 1567.398f,    -4423.649f,    108.9948f,   4.206246f   },
    { 1560.326f,    -4372.816f,    112.5343f,   6.19592f    },
    { 1521.741f,    -4390.443f,    103.8611f,   5.550147f   },
    { 1479.924f,    -4424.903f,    156.0753f,   3.054327f   },
    { 1387.427f,    -4334.854f,    150.2641f,   0.9773831f  },
    { 1481.771f,    -4466.378f,    138.0009f,   3.47321f    },
    { 1390.512f,    -4372.778f,    154.748f,    3.071766f   },
    { 1605.115f,    -4411.217f,    112.0536f,   0.06981169f },
    { 1466.144f,    -4341.917f,    140.5263f,   2.548179f   },
    { 1479.922f,    -4467.948f,    129.9536f,   3.33359f    },
    { 1397.09f,     -4405.764f,    149.5936f,   2.199115f   },
    { 1404.153f,    -4497.729f,    121.3236f,   6.0912f     },
    { 1493.337f,    -4441.268f,    137.3894f,   3.211419f   },
    { 1469.385f,    -4340.427f,    150.2859f,   2.548179f   },
    { 1385.043f,    -4317.056f,    145.6198f,   3.194002f   },
    { 1472.734f,    -4398.983f,    135.9285f,   3.47321f    },
    { 1469.135f,    -4380.587f,    117.5022f,   0.1396245f  },
    { 1389.047f,    -4339.42f,     150.2229f,   4.76475f    },
    { 1476.245f,    -4420.931f,    159.4286f,   3.630291f   },
    { 1479.87f,     -4421.628f,    161.0234f,   3.054327f   },
    { 1391.415f,    -4370.76f,     161.9061f,   3.089183f   },
    { 1394.175f,    -4385.715f,    153.2316f,   5.899214f   },
    { 1396.132f,    -4411.295f,    161.1071f,   4.66003f    },
    { 1403.262f,    -4474.733f,    103.9363f,   4.886924f   },
    { 1488.257f,    -4491.f,       130.442f,    0.03490625f },
    { 1467.707f,    -4361.327f,    105.1312f,   3.700105f   },
    { 1375.649f,    -4366.401f,    152.1661f,   0.1745321f  },
    { 1389.922f,    -4375.253f,    77.87833f,   6.0912f     },
    { 1392.398f,    -4379.628f,    172.5377f,   2.199115f   },
    { 1394.943f,    -4388.257f,    176.3171f,   3.246347f   },
    { 1481.833f,    -4466.399f,    160.8109f,   3.630291f   },
    { 1469.816f,    -4366.597f,    120.6296f,   3.159062f   },
    { 1379.802f,    -4309.967f,    146.3039f,   2.984498f   },
    { 1388.002f,    -4353.233f,    148.1396f,   5.899214f   },
    { 1378.589f,    -4296.118f,    144.691f,    5.846854f   },
    { 1470.207f,    -4395.868f,    133.8257f,   6.073746f   },
    { 1406.467f,    -4511.327f,    123.2332f,   0.1396245f  },
    { 1395.04f,     -4390.569f,    167.5848f,   3.228859f   },
    { 1480.908f,    -4422.219f,    154.6776f,   3.194002f   },
    { 1486.033f,    -4493.719f,    144.937f,    3.47321f    },
    { 1403.845f,    -4488.743f,    124.8069f,   3.700105f   },
    { 1494.733f,    -4446.885f,    140.0633f,   6.248279f   },
    { 1481.875f,    -4428.431f,    161.3601f,   3.316144f   },
    { 1384.299f,    -4332.253f,    146.5117f,   3.194002f   },
    { 1468.939f,    -4346.42f,     143.6888f,   3.054327f   },
    { 1393.356f,    -4478.347f,    125.5958f,   6.0912f     },
    { 1384.672f,    -4449.229f,    146.3165f,   4.886924f   },
    { 1486.5393f,   -4372.5333f,   117.014f,    5.951700f   },
    { 1489.1738f,   -4415.65091f,  110.5526f,   1.309994f   },
    { 1501.63171f,  -4454.74668f,  107.716637f, 0.387151f   },
    { 1518.3159f,   -4438.94873f,   82.9114f,   1.891189f   },
    { 1511.754272f, -4423.58203f,   75.781662f, 6.1763f     },
    { 1508.1212f,   -4399.4312f,    75.781662f, 3.575869f   },
    { 1515.1198f,   -4356.886719f,  81.859f,    5.87775f    },
    { 1553.78795f,  -4387.95084f,   72.565178f, 1.372812f   },
    { 1549.74023f,  -4413.03227f,   74.2219f,   0.42641f    },
    { 1528.63644f,  -4408.71850f,  118.7224f,   0.23985f    },
    { 1532.7171f,   -4399.64944f,   70.62704f,  0.13188f    },
    { 1509.3391f,   -4422.2905f,    75.24475f,  0.1554f     },
    { 1501.4160f,   -4413.1782f,    62.63250f,  0.347852f   },
    { 1499.258179f, -4395.1628f,    62.230198f, 6.02282f    },
    { 1485.33571f,  -4397.560547f,  71.07567f,  3.2190f     },
    { 1495.2693f,   -4417.2910f,    70.232471f, 3.31666f    },
    { 1498.65912f,  -4439.20613f,   69.07176f,  3.7643f     },
    { 1523.45699f,  -4393.04395f,   59.775066f, 3.71542f    },
    { 1536.62665f,  -4419.85963f,   60.4508f,   3.46193f    },
    { 1497.2632f,   -4401.54637f,   53.805511f, 2.60181f    },
    { 1497.9363f,   -4437.58008f,   52.326393f, 4.96205f    },
    { 1493.26253f,  -4402.19919f,   79.147816f, 2.2917f     }
};

static const std::vector<Position> IronForgePos =
{
    { -5196.038f, -858.4618f, 525.0447f, 6.073746f  },
    { -5195.734f, -887.6441f, 534.168f,  3.68265f   },
    { -5195.063f, -762.2795f, 510.0929f, 4.66003f   },
    { -5164.59f,  -858.3264f, 540.0117f, 5.899214f  },
    { -5130.776f, -791.1945f, 523.2938f, 5.846854f  },
    { -5127.663f, -827.1771f, 534.2573f, 4.76475f   },
    { -5227.184f, -754.8802f, 500.0329f, 5.550147f  },
    { -5197.655f, -857.8889f, 525.5248f, 2.199115f  },
    { -5227.705f, -859.0052f, 513.9084f, 6.0912f    },
    { -5227.f,    -821.7795f, 471.7424f, 3.700105f  },
    { -5131.42f,  -791.9445f, 537.8198f, 3.054327f  },
    { -5223.59f,  -889.6302f, 509.3725f, 4.886924f  },
    { -5164.124f, -825.3795f, 525.2161f, 0.9773831f },
    { -5196.168f, -826.6163f, 517.4463f, 2.111848f  },
    { -5227.393f, -757.1059f, 501.0704f, 3.47321f   },
    { -5192.556f, -784.4583f, 506.9716f, 4.729844f  },
    { -5227.965f, -792.184f,  509.1933f, 0.1396245f },
    { -5182.054f, -782.283f,  514.0707f, 4.886924f  },
    { -5152.384f, -819.2031f, 508.2252f, 0.9773831f },
    { -5220.162f, -722.941f,  501.573f,  3.700105f  },
    { -5218.438f, -879.0486f, 534.1289f, 2.111848f  },
    { -5186.096f, -846.5903f, 526.4001f, 3.054327f  },
    { -5182.972f, -816.2309f, 522.7172f, 5.550147f  },
    { -5172.745f, -854.6077f, 541.5695f, 2.548179f  },
    { -5126.936f, -816.5712f, 506.1032f, 4.76475f   },
    { -5214.637f, -850.4496f, 524.1501f, 4.729844f  },
    { -5156.693f, -818.3021f, 532.9488f, 4.66003f   },
    { -5188.997f, -876.8524f, 544.1463f, 6.073746f  },
    { -5216.222f, -817.3351f, 498.4872f, 3.630291f  },
    { -5190.08f,  -758.6545f, 507.9708f, 6.0912f    },
    { -5156.724f, -844.0851f, 529.4639f, 5.899214f  },
    { -5215.002f, -754.8802f, 488.5055f, 0.1396245f },
    { -5137.646f, -787.2882f, 502.1171f, 5.846854f  },
    { -5183.194f, -817.217f,  508.4071f, 3.68265f   },
    { -5183.191f, -848.6163f, 518.0361f, 2.199115f  },
    { -5215.972f, -785.0452f, 494.1193f, 3.47321f   },
    { -5117.396f, -791.4796f, 483.5854f, 6.0912f    },
    { -5153.132f, -781.2309f, 539.7031f, 5.899214f  },
    { -5209.993f, -710.1337f, 501.9293f, 5.846854f  },
    { -5172.809f, -848.1094f, 520.4458f, 6.0912f    },
    { -5120.552f, -812.3004f, 547.9608f, 3.68265f   },
    { -5142.92f,  -811.507f,  526.748f,  4.886924f  },
    { -5208.391f, -773.4583f, 497.451f,  4.729844f  },
    { -5181.903f, -779.1979f, 518.5895f, 0.9773831f },
    { -5208.097f, -843.934f, 514.2054f,  3.47321f   },
    { -5118.309f, -783.3246f, 545.3275f, 2.199115f  },
    { -5213.969f, -715.6684f, 493.5344f, 6.073746f  },
    { -5211.384f, -872.493f,  523.3142f, 0.1396245f },
    { -5215.563f, -812.7205f, 501.1313f, 2.548179f  },
    { -5159.971f, -819.0695f, 523.9502f, 5.550147f  },
    { -5243.21f,  -741.7934f, 479.6208f, 2.111848f  },
    { -5158.577f, -784.243f,  515.7791f, 3.054327f  },
    { -5210.179f, -809.2413f, 507.136f,  3.630291f  },
    { -5182.26f,  -818.6476f, 519.5022f, 4.66003f   },
    { -5178.493f, -870.8143f, 539.2921f, 3.700105f  },
    { -5206.622f, -741.5938f, 511.1593f, 4.76475f   },
    { -5194.976f, -759.9896f, 517.6288f, 3.630291f  }
};

static const std::vector<Position> ThunderBluffPos =
{
    { -1234.804f, -19.72239f, 206.5436f, 0.1396245f },
    { -1244.442f, -35.88308f, 206.82f,   4.729844f  },
    { -1239.212f, -11.25857f, 208.6352f, 3.700105f  },
    { -1217.165f, -15.58898f, 207.4553f, 3.68265f   },
    { -1229.332f,  -6.54617f, 208.2537f, 2.548179f  },
    { -1227.353f, -14.30225f, 206.6192f, 3.054327f  },
    { -1234.8f,   -14.12402f, 208.0964f, 6.0912f    },
    { -1246.791f, -38.59223f, 206.846f,  6.073746f  },
    { -1229.818f, -6.788249f, 209.4552f, 4.886924f  },
    { -1223.867f, -10.67551f, 205.7558f, 0.9773831f },
    { -1229.833f, -6.403429f, 208.6842f, 4.76475f   },
    { -1239.199f, -23.20622f, 207.0188f, 3.47321f   },
    { -1246.258f, -37.36089f, 208.2598f, 2.199115f  },
    { -1223.363f, -12.2462f,  201.3805f, 4.66003f   },
    { -1218.116f, -16.37305f, 199.9185f, 5.550147f  },
    { -1239.709f, -42.34294f, 204.2466f, 2.111848f  },
    { -1219.295f, -12.87424f, 206.2387f, 5.899214f  },
    { -1251.241f, -33.18164f, 209.7986f, 3.630291f  },
    { -1219.549f, -12.32769f, 207.9862f, 3.47321f   },
    { -1251.181f, -34.52919f, 206.8795f, 4.66003f   },
    { -1235.567f, -15.02116f, 205.3759f, 2.199115f  },
    { -1241.148f, -41.8049f,  205.8436f, 0.1396245f },
    { -1241.41f,  -23.09136f, 206.5933f, 3.054327f  },
    { -1235.885f, -19.49116f, 206.4422f, 3.68265f   },
    { -1234.823f, -13.99685f, 210.1406f, 6.073746f  },
    { -1220.117f, -10.93815f, 204.8297f, 4.76475f   },
    { -1219.087f, -6.230252f, 206.5717f, 5.899214f  },
    { -1235.053f, -20.39225f, 206.5732f, 3.630291f  },
    { -1239.364f, -22.23714f, 207.2047f, 4.886924f  },
    { -1245.448f, -37.35639f, 208.0733f, 3.700105f  },
    { -1222.941f, -10.68441f, 208.3044f, 0.9773831f },
    { -1238.765f, -11.7156f,  203.8905f, 2.111848f  },
    { -1251.638f, -34.5931f,  207.4821f, 6.0912f    },
    { -1229.332f,  -6.54617f, 205.5314f, 4.729844f  },
    { -1245.196f, -37.02111f, 208.2277f, 5.550147f  },
    { -1235.227f, -19.88525f, 206.9543f, 2.548179f  },
    { -1249.993f, -35.97727f, 206.9852f, 5.846854f  },
    { -1238.741f, -11.55127f, 216.4102f, 4.76475f   },
    { -1242.702f, -23.95698f, 215.8784f, 2.199115f  },
    { -1223.998f, -11.75629f, 187.3124f, 6.0912f    },
    { -1220.138f, -16.90701f, 218.7182f, 2.111848f  },
    { -1239.351f, -23.36654f, 218.1057f, 5.550147f  },
    { -1222.544f, -11.58713f, 218.9956f, 3.630291f  },
    { -1234.379f, -19.82167f, 211.3573f, 5.899214f  },
    { -1224.649f, -16.73172f, 217.2839f, 6.073746f  },
    { -1219.856f, -11.69358f, 218.5711f, 0.1396245f },
    { -1223.967f, -8.415148f, 219.2347f, 3.47321f   },
    { -1252.266f, -33.21897f, 215.823f,  3.68265f   },
    { -1244.304f, -41.49599f, 214.7235f, 3.700105f  },
    { -1245.102f, -34.69542f, 215.4592f, 4.886924f  },
    { -1239.761f, -41.99474f, 211.7772f, 6.0912f    },
    { -1219.803f, -11.18414f, 219.6471f, 4.729844f  },
    { -1219.832f, -12.19803f, 219.4899f, 5.846854f  },
    { -1236.825f, -18.4617f,  220.2076f, 4.66003f   },
    { -1239.635f, -11.55973f, 220.694f,  2.548179f  },
    { -1233.765f, -15.5765f,  216.1068f, 3.054327f  },
    { -1233.56f,  -15.80257f, 215.6199f, 0.9773831f },
    { -1240.617f, -41.39486f, 205.0362f, 5.846854f  }
};

static const std::vector<Position> UndercityPos =
{
    { 1850.231f, 257.0156f, 124.1743f, 4.729844f  },
    { 1863.302f, 193.9063f, 114.5829f, 0.9773831f },
    { 1851.997f, 212.7726f, 127.959f,  5.550147f  },
    { 1862.474f, 288.1528f, 118.4504f, 6.0912f    },
    { 1851.906f, 267.6267f, 131.5442f, 3.054327f  },
    { 1868.905f, 323.2587f, 131.801f,  0.1396245f },
    { 1849.677f, 196.5052f, 119.4152f, 2.548179f  },
    { 1870.382f, 155.8438f, 135.8888f, 5.846854f  },
    { 1863.309f, 211.9219f, 117.2065f, 5.899214f  },
    { 1849.877f, 215.7413f, 120.1931f, 6.073746f  },
    { 1864.762f, 170.5399f, 108.2692f, 4.76475f   },
    { 1839.986f, 288.4306f, 126.1348f, 3.47321f   },
    { 1875.91f,  230.566f,  125.1612f, 2.199115f  },
    { 1854.146f, 238.7622f, 131.7162f, 4.66003f   },
    { 1863.307f, 264.4583f, 123.374f,  4.886924f  },
    { 1871.578f, 266.8681f, 108.0443f, 4.66003f   },
    { 1836.901f, 185.5868f, 113.362f,  3.630291f  },
    { 1871.545f, 191.2622f, 105.8294f, 6.073746f  },
    { 1863.307f, 211.816f,  114.3906f, 4.76475f   },
    { 1841.543f, 205.1754f, 102.9691f, 3.47321f   },
    { 1843.304f, 273.4757f, 104.6566f, 6.0912f    },
    { 1870.818f, 167.0938f, 126.3066f, 4.729844f  },
    { 1840.653f, 227.6319f, 106.8095f, 0.1396245f },
    { 1863.299f, 282.1806f, 110.9902f, 2.199115f  },
    { 1875.688f, 230.5278f, 112.7081f, 3.054327f  },
    { 1872.264f, 311.1458f, 119.7756f, 3.68265f   },
    { 1871.248f, 297.1684f, 113.6078f, 5.550147f  },
    { 1863.293f, 186.4896f, 114.6143f, 5.846854f  },
    { 1838.384f, 252.3264f, 103.8479f, 3.700105f  },
    { 1886.804f, 166.3976f, 125.2679f, 2.111848f  },
    { 1863.363f, 237.5417f, 125.3641f, 0.9773831f },
    { 1863.307f, 267.875f,  113.7794f, 5.899214f  },
    { 1845.602f, 299.4445f, 120.9578f, 4.886924f  },
    { 1871.884f, 217.2656f, 108.2966f, 2.548179f  },
    { 1867.459f, 240.2357f, 106.0639f, 6.0912f    },
    { 1863.326f, 298.4879f, 121.1103f, 3.054327f  },
    { 1844.776f, 287.776f,  131.6692f, 4.76475f   },
    { 1842.595f, 299.8854f, 132.9048f, 5.846854f  },
    { 1843.754f, 233.0833f, 122.607f,  3.68265f   },
    { 1865.563f, 238.7674f, 127.128f,  5.550147f  },
    { 1863.302f, 282.6076f, 117.6718f, 2.548179f  },
    { 1850.063f, 218.7344f, 116.5234f, 4.886924f  },
    { 1852.528f, 257.8333f, 125.5587f, 5.899214f  },
    { 1870.385f, 321.809f,  123.7424f, 4.66003f   },
    { 1864.694f, 167.474f,  111.3632f, 0.1396245f },
    { 1846.231f, 194.2656f, 108.0038f, 3.700105f  },
    { 1876.434f, 227.1129f, 116.7266f, 4.729844f  },
    { 1839.993f, 245.0399f, 120.8441f, 2.199115f  },
    { 1864.042f, 204.4774f, 105.6403f, 3.630291f  },
    { 1875.594f, 246.9271f, 110.0379f, 2.111848f  },
    { 1850.892f, 273.6059f, 133.6044f, 0.9773831f },
    { 1863.3f,   186.2188f, 118.3104f, 3.47321f   },
    { 1851.578f, 203.2604f, 118.5638f, 6.0912f    },
    { 1863.307f, 259.8038f, 116.5421f, 6.073746f  },
    { 1877.592f, 247.3872f, 128.022f,  3.68265f   },
    { 1850.288f, 267.309f,  125.0537f, 3.630291f  }
};

static const std::vector<Position> DarnassusPos =
{
    { 8578.888f, 975.2604f, 42.48742f, 5.846854f  },
    { 8574.236f, 944.2083f, 44.71943f, 4.76475f   },
    { 8517.067f, 986.0851f, 66.32562f, 4.729844f  },
    { 8553.734f, 780.0504f, 63.21661f, 4.886924f  },
    { 8537.763f, 877.8924f, 76.7791f,  3.054327f  },
    { 8572.691f, 814.7379f, 72.4253f,  3.68265f   },
    { 8572.691f, 814.7379f, 72.4253f,  3.68265f   },
    { 8494.191f, 943.868f,  59.0681f,  6.073746f  },
    { 8536.576f, 873.7222f, 45.29478f, 0.1396245f },
    { 8550.191f, 850.7222f, 57.6362f,  3.700105f  },
    { 8554.281f, 875.8316f, 48.10747f, 5.550147f  },
    { 8590.731f, 846.9427f, 56.89664f, 2.199115f  },
    { 8519.5f,   949.7708f, 63.29575f, 3.630291f  },
    { 8508.24f,  838.3646f, 77.00415f, 4.66003f   },
    { 8588.622f, 912.0434f, 49.60857f, 0.9773831f },
    { 8538.786f, 820.7361f, 67.0003f,  6.0912f    },
    { 8488.077f, 983.2379f, 59.87747f, 2.111848f  },
    { 8494.68f,  911.783f,  72.29862f, 2.548179f  },
    { 8556.297f, 920.9479f, 42.13089f, 3.47321f   },
    { 8571.629f, 880.1511f, 53.78056f, 5.899214f  },
    { 8544.278f, 885.059f,  70.3073f,  0.1396245f },
    { 8551.224f, 947.6059f, 60.74737f, 6.0912f    },
    { 8586.716f, 913.4774f, 42.5911f,  4.76475f   },
    { 8617.442f, 917.658f,  41.92455f, 4.886924f  },
    { 8519.375f, 917.842f,  74.22758f, 2.111848f  },
    { 8550.322f, 910.9809f, 52.84513f, 3.700105f  },
    { 8582.255f, 848.0608f, 53.87154f, 5.899214f  },
    { 8547.279f, 964.1684f, 45.09663f, 5.550147f  },
    { 8581.158f, 881.2344f, 54.83494f, 0.9773831f },
    { 8550.932f, 817.2396f, 60.80384f, 3.630291f  },
    { 8550.214f, 787.1684f, 66.42948f, 4.729844f  },
    { 8583.88f,  948.4114f, 41.32378f, 5.846854f  },
    { 8550.997f, 848.8594f, 70.56313f, 3.47321f   },
    { 8517.45f,  879.5555f, 83.80603f, 6.073746f  },
    { 8558.55f,  838.934f,  56.89937f, 4.66003f   },
    { 8617.526f, 851.5955f, 37.39491f, 3.68265f   },
    { 8579.229f, 911.8906f, 44.37334f, 3.054327f  },
    { 8581.771f, 817.0295f, 30.07061f, 2.199115f  },
    { 8514.054f, 848.6059f, 59.20383f, 2.548179f  },
    { 8570.65f,  885.1719f, 59.11485f, 2.548179f  },
    { 8576.803f, 814.3611f, 50.15007f, 4.66003f   },
    { 8697.891f, 991.0841f, 39.18531f, 6.0912f    },
    { 8547.403f, 974.4879f, 63.7893f,  5.846854f  },
    { 8553.929f, 853.6476f, 84.47609f, 0.1396245f },
    { 8507.603f, 878.8854f, 70.23988f, 5.899214f  },
    { 8570.95f,  854.1406f, 65.7302f,  3.054327f  },
    { 8560.618f, 777.342f,  79.87446f, 4.886924f  },
    { 8542.07f,  852.0174f, 64.99033f, 3.700105f  },
    { 8514.364f, 940.0868f, 64.65899f, 4.76475f   },
    { 8526.2f,   848.8542f, 63.1242f,  2.199115f  },
    { 8571.85f,  913.1511f, 43.11662f, 6.073746f  },
    { 8591.914f, 901.6493f, 26.83536f, 5.550147f  },
    { 8539.892f, 914.3368f, 45.99331f, 3.630291f  },
    { 8578.143f, 948.3264f, 62.56763f, 2.111848f  },
    { 8539.493f, 887.2274f, 79.56437f, 3.47321f   },
    { 8538.561f, 951.6632f, 69.08958f, 4.729844f  },
    { 8523.006f, 907.7413f, 72.85262f, 0.9773831f },
    { 8520.907f, 813.0208f, 81.70242f, 3.68265f   },
    { 8554.825f, 813.0746f, 78.88226f, 6.0912f    }
};

static const std::unordered_map<uint32, std::vector<Position> const&> pos =
{
    { STRANGLETHORN_VALE, BootyBayPos     },
    { STORMWIND,          StormwindPos    },
    { ORGRIMMAR,          OrgrimmarPos    },
    { DUROTAR,            OrgrimmarPos    },
    { DUN_MOROGH,         IronForgePos    },
    { IRONFORGE,          IronForgePos    },
    { THUNDERBLUFF,       ThunderBluffPos },
    { UNDERCITY,          UndercityPos    },
    { TIRISFAL_GLADES,    UndercityPos    },
    { TELDRASSIL,         DarnassusPos    }
};

std::array<uint32, 23> const fireworkIds =
{
    FIREWORK_SHOW_TYPE_1_RED,
    FIREWORK_SHOW_TYPE_2_RED,
    FIREWORK_SHOW_TYPE_1_RED_BIG,
    FIREWORK_SHOW_TYPE_2_RED_BIG,
    FIREWORK_SHOW_TYPE_1_BLUE,
    FIREWORK_SHOW_TYPE_2_BLUE,
    FIREWORK_SHOW_TYPE_1_BLUE_BIG,
    FIREWORK_SHOW_TYPE_2_BLUE_BIG,
    FIREWORK_SHOW_TYPE_1_GREEN,
    FIREWORK_SHOW_TYPE_2_GREEN_BIG,
    FIREWORK_SHOW_TYPE_1_GREEN_BIG,
    FIREWORK_SHOW_TYPE_2_GREEN,
    FIREWORK_SHOW_TYPE_1_WHITE,
    FIREWORK_SHOW_TYPE_1_WHITE_BIG,
    FIREWORK_SHOW_TYPE_2_WHITE,
    FIREWORK_SHOW_TYPE_2_WHITE_BIG,
    FIREWORK_SHOW_TYPE_1_YELLOW,
    FIREWORK_SHOW_TYPE_1_YELLOW_BIG,
    FIREWORK_SHOW_TYPE_2_YELLOW,
    FIREWORK_SHOW_TYPE_2_YELLOW_BIG,
    FIREWORK_SHOW_TYPE_2_PURPLE,
    FIREWORK_SHOW_TYPE_1_PURPLE_BIG,
    FIREWORK_SHOW_TYPE_2_PURPLE_BIG
};

std::array<uint32, 12> const fireworkBigIds =
{
    FIREWORK_SHOW_TYPE_1_RED_BIG,
    FIREWORK_SHOW_TYPE_2_RED_BIG,
    FIREWORK_SHOW_TYPE_1_BLUE_BIG,
    FIREWORK_SHOW_TYPE_2_BLUE_BIG,
    FIREWORK_SHOW_TYPE_2_GREEN_BIG,
    FIREWORK_SHOW_TYPE_1_GREEN_BIG,
    FIREWORK_SHOW_TYPE_1_WHITE_BIG,
    FIREWORK_SHOW_TYPE_2_WHITE_BIG,
    FIREWORK_SHOW_TYPE_1_YELLOW_BIG,
    FIREWORK_SHOW_TYPE_2_YELLOW_BIG,
    FIREWORK_SHOW_TYPE_1_PURPLE_BIG,
    FIREWORK_SHOW_TYPE_2_PURPLE_BIG
};

struct go_cheer_speakerAI : public GameObjectAI
{
    go_cheer_speakerAI(GameObject* go) : GameObjectAI(go)
    {
        m_started = false;
        m_big = false;
    }

    uint32 CheerPicker()
    {
        switch (urand(0, 3))
        {
            case 0:
                return SOUND_CHEER_1;
            case 1:
                return SOUND_CHEER_2;
            case 2:
                return SOUND_CHEER_3;
        }
        return SOUND_CHEER_4;
    }

    uint32 FireworksPicker()
    {
        return SelectRandomContainerElement(fireworkIds);
    }

    uint32 FireworksBIGOnlyPicker()
    {
        return SelectRandomContainerElement(fireworkBigIds);
    }

    void UpdateAI(uint32 const diff) override
    {
        m_events.Update(diff);

        time_t rawtime = time(nullptr);
        struct tm* localTm;
        localTm = localtime(&rawtime);

        // Start
        if ((localTm->tm_min == 0 && localTm->tm_sec == 0) && !m_started && sGameEventMgr.IsActiveEvent(GAME_EVENT_FIREWORKS))
        {
            m_events.ScheduleEvent(EVENT_CHEER, Seconds(1));
            m_events.ScheduleEvent(EVENT_FIRE, Seconds(1));
            m_started = true;
        }

        // Event is active
        if ((localTm->tm_min >= 0 && localTm->tm_sec >= 1 && localTm->tm_min <= 9 && localTm->tm_sec <= 59 && !m_started) && sGameEventMgr.IsActiveEvent(GAME_EVENT_FIREWORKS))
        {
            m_events.ScheduleEvent(EVENT_FIRE, Seconds(1));
            m_started = true;
        }

        // Stop
        if ((localTm->tm_min == 10 && localTm->tm_sec == 0) && m_started == true)
        {
            m_started = false;
            m_events.ScheduleEvent(EVENT_CHEER, Seconds(1));
            m_events.CancelEvent(EVENT_FIRE);
        }

        // New Year (Only!) - One more big bang!
        if ((localTm->tm_min == 10 && localTm->tm_sec == 30 && localTm->tm_hour == 0) && sGameEventMgr.IsActiveEvent(GAME_EVENT_FIREWORKS) && m_big == false)
        {
            m_big = true;
            m_events.ScheduleEvent(EVENT_CHEER, Seconds(1));
            m_events.ScheduleEvent(EVENT_FIRE, Seconds(1));
            m_events.ScheduleEvent(EVENT_FIRE, Seconds(1));
            m_events.ScheduleEvent(EVENT_FIRE, Seconds(1));
            m_events.ScheduleEvent(EVENT_FIRE, Seconds(1));
            m_events.ScheduleEvent(EVENT_FIRE, Seconds(1));
            m_events.ScheduleEvent(EVENT_FIRE, Seconds(1));
            m_events.ScheduleEvent(EVENT_FIRE, Seconds(1));
            m_events.ScheduleEvent(EVENT_FIRE, Seconds(1));
            m_events.ScheduleEvent(EVENT_FIRE, Seconds(1));
            m_events.ScheduleEvent(EVENT_FIRE, Seconds(1));
        }

        while (uint32 eventId = m_events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_CHEER:
                {
                    me->PlayDistanceSound(CheerPicker());
                    break;
                }
                case EVENT_FIRE:
                {
                    auto it = pos.find(me->GetZoneId());
                    if (it != pos.end())
                    {
                        Position const& rndpos = SelectRandomContainerElement(it->second);
                        float rndrot = frand(-1.0000000f, 1.0000000f);
                        float rndrot2 = frand(-1.0000000f, 1.0000000f);

                        if (m_big)
                        {
                            if (GameObject* firework = me->SummonGameObject(FireworksBIGOnlyPicker(), rndpos.x, rndpos.y, rndpos.z, rndpos.o, 0.f, 0.f, rndrot, rndrot2, 1))
                            {
                                firework->SetRespawnTime(0);
                                firework->Delete();
                            }
                        }
                        else
                        {
                            if (GameObject* firework = me->SummonGameObject(FireworksPicker(), rndpos.x, rndpos.y, rndpos.z, rndpos.o, 0.f, 0.f, rndrot, rndrot2, 1))
                            {
                                firework->SetRespawnTime(0);
                                firework->Delete();
                            }
                        }
                    }

                    if (m_started == true)
                        m_events.ScheduleEvent(EVENT_FIRE, Seconds(1), Seconds(2));

                    break;
                }
                default:
                    break;
            }
        }
    }
private:
    EventMap m_events;
    bool m_started;
    bool m_big;
};

GameObjectAI* GetAI_go_cheer_speaker(GameObject* gameobject)
{
    return new go_cheer_speakerAI(gameobject);
}

void AddSC_event_fireworks()
{
    Script* newscript;
    newscript = new Script;
    newscript->Name = "go_cheer_speaker";
    newscript->GOGetAI = &GetAI_go_cheer_speaker;
    newscript->RegisterSelf();
}
