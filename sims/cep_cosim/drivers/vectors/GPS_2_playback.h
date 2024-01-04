//************************************************************************
// Copyright 2022 Massachusetts Institute of Technology
//
// This file is auto-generated for test: GPS_2. Do not modify!!!
//
// Generated on: Dec  5 2023 14:33:25
//************************************************************************
#ifndef GPS_2_playback_H
#define GPS_2_playback_H

#ifndef PLAYBACK_CMD_H
#define PLAYBACK_CMD_H
// Write to : <physicalAdr> <writeData>
#define WRITE__CMD  1
// Read and compare: <physicalAdr> <Data2Compare>
#define RDnCMP_CMD  2
// Read and spin until match : <physicalAdr> <Data2Match> <mask> <timeout>
#define RDSPIN_CMD  3

#define WRITE__CMD_SIZE  3
#define RDnCMP_CMD_SIZE  3
#define RDSPIN_CMD_SIZE  5
#endif

// GPS_2 command sequences to playback
uint64_t GPS_2_playback[] = { 
	  WRITE__CMD, 0x70092038, 0x0000000000000001 // 1
	, WRITE__CMD, 0x70092038, 0x0000000000000001 // 2
	, WRITE__CMD, 0x70092038, 0x0000000000000001 // 3
	, WRITE__CMD, 0x70092038, 0x0000000000000001 // 4
	, WRITE__CMD, 0x70092038, 0x0000000000000001 // 5
	, WRITE__CMD, 0x70092038, 0x0000000000000000 // 6
	, WRITE__CMD, 0x70092030, 0x0000000000000000 // 7
	, WRITE__CMD, 0x70092040, 0xaaaaaaaaaaaaaaaa // 8
	, WRITE__CMD, 0x70092048, 0xaaaaaaaaaaaaaaaa // 9
	, WRITE__CMD, 0x70092050, 0xaaaaaaaaaaaaaaaa // 10
	, WRITE__CMD, 0x70092030, 0x0000000000000001 // 11
	, WRITE__CMD, 0x70092000, 0x0000000000000001 // 12
	, WRITE__CMD, 0x70092000, 0x0000000000000000 // 13
	, RDSPIN_CMD, 0x70092000, 0x0000000000000002, 0x2, 0x1f4 // 14
	, RDnCMP_CMD, 0x70092008, 0x0000000000001907 // 15
	, RDnCMP_CMD, 0x70092010, 0x924110552bd74e7f // 16
	, RDnCMP_CMD, 0x70092018, 0xc62d21cd7f83b3f9 // 17
	, RDnCMP_CMD, 0x70092020, 0x0609e8f9dc6348b0 // 18
	, RDnCMP_CMD, 0x70092028, 0xe718fdc8b191a85d // 19
	, WRITE__CMD, 0x70092040, 0x5555555555555555 // 20
	, WRITE__CMD, 0x70092048, 0x5555555555555555 // 21
	, WRITE__CMD, 0x70092050, 0x5555555555555555 // 22
	, WRITE__CMD, 0x70092030, 0x0000000000000002 // 23
	, WRITE__CMD, 0x70092000, 0x0000000000000001 // 24
	, WRITE__CMD, 0x70092000, 0x0000000000000000 // 25
	, RDSPIN_CMD, 0x70092000, 0x0000000000000002, 0x2, 0x1f4 // 26
	, RDnCMP_CMD, 0x70092008, 0x0000000000001c87 // 27
	, RDnCMP_CMD, 0x70092010, 0x800d9d1eb5ef85ca // 28
	, RDnCMP_CMD, 0x70092018, 0x7b25290c95bf1c92 // 29
	, RDnCMP_CMD, 0x70092020, 0x1c5c70ef948d4185 // 30
	, RDnCMP_CMD, 0x70092028, 0xbca1f30b29bf728b // 31
	, WRITE__CMD, 0x70092040, 0x4f998d18cc33e1d4 // 32
	, WRITE__CMD, 0x70092048, 0xeee707ed80a2efd6 // 33
	, WRITE__CMD, 0x70092050, 0x81f1632cf34c61d2 // 34
	, WRITE__CMD, 0x70092030, 0x0000000000000003 // 35
	, WRITE__CMD, 0x70092000, 0x0000000000000001 // 36
	, WRITE__CMD, 0x70092000, 0x0000000000000000 // 37
	, RDSPIN_CMD, 0x70092000, 0x0000000000000002, 0x2, 0x1f4 // 38
	, RDnCMP_CMD, 0x70092008, 0x0000000000001e47 // 39
	, RDnCMP_CMD, 0x70092010, 0x892bdbbb7af3e010 // 40
	, RDnCMP_CMD, 0x70092018, 0xa5a12d6c60a14b27 // 41
	, RDnCMP_CMD, 0x70092020, 0xf3e5dc4ada003d5b // 42
	, RDnCMP_CMD, 0x70092028, 0x09d5c68778042f39 // 43
	, WRITE__CMD, 0x70092040, 0x5aaec9e4afbce409 // 44
	, WRITE__CMD, 0x70092048, 0xd36088223ba57b12 // 45
	, WRITE__CMD, 0x70092050, 0xaf239bc1567f0f35 // 46
	, WRITE__CMD, 0x70092030, 0x0000000000000004 // 47
	, WRITE__CMD, 0x70092000, 0x0000000000000001 // 48
	, WRITE__CMD, 0x70092000, 0x0000000000000000 // 49
	, RDSPIN_CMD, 0x70092000, 0x0000000000000002, 0x2, 0x1f4 // 50
	, RDnCMP_CMD, 0x70092008, 0x0000000000001f27 // 51
	, RDnCMP_CMD, 0x70092010, 0x8db8f8e99d7dd2fd // 52
	, RDnCMP_CMD, 0x70092018, 0xcae32f5c1a2e60fd // 53
	, RDnCMP_CMD, 0x70092020, 0x326b7dc8c54f70d6 // 54
	, RDnCMP_CMD, 0x70092028, 0xf4c05502c74df53d // 55
	, WRITE__CMD, 0x70092040, 0x01ea7b17a7fd42bf // 56
	, WRITE__CMD, 0x70092048, 0x6a5de4296cac5cbc // 57
	, WRITE__CMD, 0x70092050, 0x30a595e758ca18e3 // 58
	, WRITE__CMD, 0x70092030, 0x0000000000000005 // 59
	, WRITE__CMD, 0x70092000, 0x0000000000000001 // 60
	, WRITE__CMD, 0x70092000, 0x0000000000000000 // 61
	, RDSPIN_CMD, 0x70092000, 0x0000000000000002, 0x2, 0x1f4 // 62
	, RDnCMP_CMD, 0x70092008, 0x00000000000012d8 // 63
	, RDnCMP_CMD, 0x70092010, 0x8ff16940eebacb8b // 64
	, RDnCMP_CMD, 0x70092018, 0x7d422e442769f510 // 65
	, RDnCMP_CMD, 0x70092020, 0x907b76138e08d6bf // 66
	, RDnCMP_CMD, 0x70092028, 0x371df7234163b52b // 67
	, WRITE__CMD, 0x70092040, 0xc399f928c9bc8ad1 // 68
	, WRITE__CMD, 0x70092048, 0x5634551099e439d3 // 69
	, WRITE__CMD, 0x70092050, 0x01346922bf63271c // 70
	, WRITE__CMD, 0x70092030, 0x0000000000000006 // 71
	, WRITE__CMD, 0x70092000, 0x0000000000000001 // 72
	, WRITE__CMD, 0x70092000, 0x0000000000000000 // 73
	, RDSPIN_CMD, 0x70092000, 0x0000000000000002, 0x2, 0x1f4 // 74
	, RDnCMP_CMD, 0x70092008, 0x0000000000001968 // 75
	, RDnCMP_CMD, 0x70092010, 0x8ed5a19457594730 // 76
	, RDnCMP_CMD, 0x70092018, 0x2692aec839ca3fe6 // 77
	, RDnCMP_CMD, 0x70092020, 0xbfe2b390ab9eb882 // 78
	, RDnCMP_CMD, 0x70092028, 0x7845d0ec2f4bd6d2 // 79
	, WRITE__CMD, 0x70092040, 0xa110c7f55fdf9a1b // 80
	, WRITE__CMD, 0x70092048, 0x3b1bbfc80fa1f11b // 81
	, WRITE__CMD, 0x70092050, 0x0a8d722ffbcec2c1 // 82
	, WRITE__CMD, 0x70092030, 0x0000000000000007 // 83
	, WRITE__CMD, 0x70092000, 0x0000000000000001 // 84
	, WRITE__CMD, 0x70092000, 0x0000000000000000 // 85
	, RDSPIN_CMD, 0x70092000, 0x0000000000000002, 0x2, 0x1f4 // 86
	, RDnCMP_CMD, 0x70092008, 0x00000000000012cf // 87
	, RDnCMP_CMD, 0x70092010, 0x8e47c5fe0ba8816d // 88
	, RDnCMP_CMD, 0x70092018, 0x8b7aee8e369bda9d // 89
	, RDnCMP_CMD, 0x70092020, 0x852702eaafa0f28c // 90
	, RDnCMP_CMD, 0x70092028, 0x4872d6a142f3b61a // 91
	, WRITE__CMD, 0x70092040, 0x536cb5f5b3cf161d // 92
	, WRITE__CMD, 0x70092048, 0x560c7821d7a550fc // 93
	, WRITE__CMD, 0x70092050, 0x2bea08ccf77d2426 // 94
	, WRITE__CMD, 0x70092030, 0x0000000000000008 // 95
	, WRITE__CMD, 0x70092000, 0x0000000000000001 // 96
	, WRITE__CMD, 0x70092000, 0x0000000000000000 // 97
	, RDSPIN_CMD, 0x70092000, 0x0000000000000002, 0x2, 0x1f4 // 98
	, RDnCMP_CMD, 0x70092008, 0x0000000000001963 // 99
	, RDnCMP_CMD, 0x70092010, 0x8e0ef7cb25d06243 // 100
	, RDnCMP_CMD, 0x70092018, 0x5d8ecead31332820 // 101
	, RDnCMP_CMD, 0x70092020, 0x722ad677603d9b26 // 102
	, RDnCMP_CMD, 0x70092028, 0xac41c6d06fa100b2 // 103
	, WRITE__CMD, 0x70092040, 0xdbad6a210e8b7623 // 104
	, WRITE__CMD, 0x70092048, 0x8f9188fe37b9601a // 105
	, WRITE__CMD, 0x70092050, 0x14693ee541a33904 // 106
	, WRITE__CMD, 0x70092030, 0x0000000000000009 // 107
	, WRITE__CMD, 0x70092000, 0x0000000000000001 // 108
	, WRITE__CMD, 0x70092000, 0x0000000000000000 // 109
	, RDSPIN_CMD, 0x70092000, 0x0000000000000002, 0x2, 0x1f4 // 110
	, RDnCMP_CMD, 0x70092008, 0x0000000000001cb5 // 111
	, RDnCMP_CMD, 0x70092010, 0x8e2a6ed1b2ec13d4 // 112
	, RDnCMP_CMD, 0x70092018, 0x36f4debcb2e7517e // 113
	, RDnCMP_CMD, 0x70092020, 0x12341d66d9e34a1c // 114
	, RDnCMP_CMD, 0x70092028, 0x6e38679e4a510419 // 115
	, WRITE__CMD, 0x70092040, 0x059734e64b4a7ad7 // 116
	, WRITE__CMD, 0x70092048, 0xb3c010cd743511fb // 117
	, WRITE__CMD, 0x70092050, 0x076d1003ec7770e7 // 118
	, WRITE__CMD, 0x70092030, 0x000000000000000a // 119
	, WRITE__CMD, 0x70092000, 0x0000000000000001 // 120
	, WRITE__CMD, 0x70092000, 0x0000000000000000 // 121
	, RDSPIN_CMD, 0x70092000, 0x0000000000000002, 0x2, 0x1f4 // 122
	, RDnCMP_CMD, 0x70092008, 0x0000000000001a25 // 123
	, RDnCMP_CMD, 0x70092010, 0x8e38225cf9722b1f // 124
	, RDnCMP_CMD, 0x70092018, 0x8349d6b4730d6dd1 // 125
	, RDnCMP_CMD, 0x70092020, 0x40ced28cb40ac3bd // 126
	, RDnCMP_CMD, 0x70092028, 0x3a2b2ea93b2d9b0e // 127
	, WRITE__CMD, 0x70092040, 0xc5a964cff0a119e7 // 128
	, WRITE__CMD, 0x70092048, 0xe1f86f0b08bb83bf // 129
	, WRITE__CMD, 0x70092050, 0xf96221d9545487ef // 130
	, WRITE__CMD, 0x70092030, 0x000000000000000b // 131
	, WRITE__CMD, 0x70092000, 0x0000000000000001 // 132
	, WRITE__CMD, 0x70092000, 0x0000000000000000 // 133
	, RDSPIN_CMD, 0x70092000, 0x0000000000000002, 0x2, 0x1f4 // 134
	, RDnCMP_CMD, 0x70092008, 0x0000000000001d16 // 135
	, RDnCMP_CMD, 0x70092010, 0x8e31041a5cbd377a // 136
	, RDnCMP_CMD, 0x70092018, 0x599752b013f87386 // 137
	, RDnCMP_CMD, 0x70092020, 0xf30016114e028ac6 // 138
	, RDnCMP_CMD, 0x70092028, 0x9f0d7b4e430322c0 // 139
	, WRITE__CMD, 0x70092040, 0xb8acfadcb0cf0f28 // 140
	, WRITE__CMD, 0x70092048, 0xd3e68c1e5d796a2b // 141
	, WRITE__CMD, 0x70092050, 0x67bfcc12ba1221fe // 142
	, WRITE__CMD, 0x70092030, 0x000000000000000c // 143
	, WRITE__CMD, 0x70092000, 0x0000000000000001 // 144
	, WRITE__CMD, 0x70092000, 0x0000000000000000 // 145
	, RDSPIN_CMD, 0x70092000, 0x0000000000000002, 0x2, 0x1f4 // 146
	, RDnCMP_CMD, 0x70092008, 0x0000000000001f43 // 147
	, RDnCMP_CMD, 0x70092010, 0x8e3597390e5ab948 // 148
	, RDnCMP_CMD, 0x70092018, 0xb4f810b22382fcad // 149
	, RDnCMP_CMD, 0x70092020, 0xbc09ee27f777f5a2 // 150
	, RDnCMP_CMD, 0x70092028, 0x1e188e3f0739f02c // 151
	, WRITE__CMD, 0x70092040, 0x1e41b31347ed25c6 // 152
	, WRITE__CMD, 0x70092048, 0xefc1a12ace7ff9bb // 153
	, WRITE__CMD, 0x70092050, 0x5cb06bdb0146ddc7 // 154
	, WRITE__CMD, 0x70092030, 0x000000000000000d // 155
	, WRITE__CMD, 0x70092000, 0x0000000000000001 // 156
	, WRITE__CMD, 0x70092000, 0x0000000000000000 // 157
	, RDSPIN_CMD, 0x70092000, 0x0000000000000002, 0x2, 0x1f4 // 158
	, RDnCMP_CMD, 0x70092008, 0x0000000000001fa5 // 159
	, RDnCMP_CMD, 0x70092010, 0x8e37dea8a7297e51 // 160
	, RDnCMP_CMD, 0x70092018, 0xc24fb1b33bbfbb38 // 161
	, RDnCMP_CMD, 0x70092020, 0x7f3393f51f39ce92 // 162
	, RDnCMP_CMD, 0x70092028, 0x88d435a603649b1f // 163
	, WRITE__CMD, 0x70092040, 0xd6655627fcac3e0d // 164
	, WRITE__CMD, 0x70092048, 0xc62c3e0e15e8cebe // 165
	, WRITE__CMD, 0x70092050, 0x3118352992249f23 // 166
	, WRITE__CMD, 0x70092030, 0x000000000000000e // 167
	, WRITE__CMD, 0x70092000, 0x0000000000000001 // 168
	, WRITE__CMD, 0x70092000, 0x0000000000000000 // 169
	, RDSPIN_CMD, 0x70092000, 0x0000000000000002, 0x2, 0x1f4 // 170
	, RDnCMP_CMD, 0x70092008, 0x0000000000001fd6 // 171
	, RDnCMP_CMD, 0x70092010, 0x8e36fa6073909ddd // 172
	, RDnCMP_CMD, 0x70092018, 0x79146133b7a118f2 // 173
	, RDnCMP_CMD, 0x70092020, 0xfb3d04ecec19e1a6 // 174
	, RDnCMP_CMD, 0x70092028, 0xf295b608ad528c18 // 175
	, WRITE__CMD, 0x70092040, 0x888fef3857c96bdc // 176
	, WRITE__CMD, 0x70092048, 0xaf8f43e9c20d740b // 177
	, WRITE__CMD, 0x70092050, 0xbda020c174a176f8 // 178
	, WRITE__CMD, 0x70092030, 0x000000000000000f // 179
	, WRITE__CMD, 0x70092000, 0x0000000000000001 // 180
	, WRITE__CMD, 0x70092000, 0x0000000000000000 // 181
	, RDSPIN_CMD, 0x70092000, 0x0000000000000002, 0x2, 0x1f4 // 182
	, RDnCMP_CMD, 0x70092008, 0x0000000000001fef // 183
	, RDnCMP_CMD, 0x70092010, 0x8e36680419cc6c1b // 184
	, RDnCMP_CMD, 0x70092018, 0x24b98973f1ae4917 // 185
	, RDnCMP_CMD, 0x70092020, 0x44884ad57b683a79 // 186
	, RDnCMP_CMD, 0x70092028, 0xe16ee6f6314f4010 // 187
	, WRITE__CMD, 0x70092040, 0xa52175eaee3f551d // 188
	, WRITE__CMD, 0x70092048, 0xa711c41e1b16afcd // 189
	, WRITE__CMD, 0x70092050, 0x754b3b1a7fa1bbd3 // 190
	, WRITE__CMD, 0x70092030, 0x0000000000000010 // 191
	, WRITE__CMD, 0x70092000, 0x0000000000000001 // 192
	, WRITE__CMD, 0x70092000, 0x0000000000000000 // 193
	, RDSPIN_CMD, 0x70092000, 0x0000000000000002, 0x2, 0x1f4 // 194
	, RDnCMP_CMD, 0x70092008, 0x0000000000001ff3 // 195
	, RDnCMP_CMD, 0x70092010, 0x8e3621362ce214f8 // 196
	, RDnCMP_CMD, 0x70092018, 0x0a6f7d53d2a9e1e5 // 197
	, RDnCMP_CMD, 0x70092020, 0x8f1962091e2d7239 // 198
	, RDnCMP_CMD, 0x70092028, 0xa117f0be203fefd8 // 199
	, WRITE__CMD, 0x70092040, 0xae6bc90ff36dc9dd // 200
	, WRITE__CMD, 0x70092048, 0xd61475f19d1ee6fc // 201
	, WRITE__CMD, 0x70092050, 0xa1c938e4831cfdd0 // 202
	, WRITE__CMD, 0x70092030, 0x0000000000000011 // 203
	, WRITE__CMD, 0x70092000, 0x0000000000000001 // 204
	, WRITE__CMD, 0x70092000, 0x0000000000000000 // 205
	, RDSPIN_CMD, 0x70092000, 0x0000000000000002, 0x2, 0x1f4 // 206
	, RDnCMP_CMD, 0x70092008, 0x0000000000001370 // 207
	, RDnCMP_CMD, 0x70092010, 0x8e3605af36752889 // 208
	, RDnCMP_CMD, 0x70092018, 0x9d040743c32a359c // 209
	, RDnCMP_CMD, 0x70092020, 0x078ab69b29366aa9 // 210
	, RDnCMP_CMD, 0x70092028, 0x2ceafbe32c24e3d5 // 211
	, WRITE__CMD, 0x70092040, 0xd791e2fa0fbcdb28 // 212
	, WRITE__CMD, 0x70092048, 0x11b50bd24cc5b40e // 213
	, WRITE__CMD, 0x70092050, 0x9d8310191f5e13c2 // 214
	, WRITE__CMD, 0x70092030, 0x0000000000000012 // 215
	, WRITE__CMD, 0x70092000, 0x0000000000000001 // 216
	, WRITE__CMD, 0x70092000, 0x0000000000000000 // 217
	, RDSPIN_CMD, 0x70092000, 0x0000000000000002, 0x2, 0x1f4 // 218
	, RDnCMP_CMD, 0x70092008, 0x00000000000019bc // 219
	, RDnCMP_CMD, 0x70092010, 0x8e3617e3bb3eb6b1 // 220
	, RDnCMP_CMD, 0x70092018, 0x56b1ba4bcbebdfa0 // 221
	, RDnCMP_CMD, 0x70092020, 0xeff3e9505ac7bb88 // 222
	, RDnCMP_CMD, 0x70092028, 0xa87eac7406fbf26b // 223
	, WRITE__CMD, 0x70092040, 0xbedf47e353c1a7de // 224
	, WRITE__CMD, 0x70092048, 0xbd28e0320441542a // 225
	, WRITE__CMD, 0x70092050, 0x16e80126c76cb3c2 // 226
	, WRITE__CMD, 0x70092030, 0x0000000000000013 // 227
	, WRITE__CMD, 0x70092000, 0x0000000000000001 // 228
	, WRITE__CMD, 0x70092000, 0x0000000000000000 // 229
	, RDSPIN_CMD, 0x70092000, 0x0000000000000002, 0x2, 0x1f4 // 230
	, RDnCMP_CMD, 0x70092008, 0x0000000000001cda // 231
	, RDnCMP_CMD, 0x70092010, 0x8e361ec5fd9b79ad // 232
	, RDnCMP_CMD, 0x70092018, 0x336b64cfcf8b2abe // 233
	, RDnCMP_CMD, 0x70092020, 0xc2d2bcb5ef56a541 // 234
	, RDnCMP_CMD, 0x70092028, 0xb3adfedf54726528 // 235
	, WRITE__CMD, 0x70092040, 0x3b84edd57a5bfa0d // 236
	, WRITE__CMD, 0x70092048, 0x3d2e39cbd3ba1724 // 237
	, WRITE__CMD, 0x70092050, 0x87eda637e48ce0cd // 238
	, WRITE__CMD, 0x70092030, 0x0000000000000014 // 239
	, WRITE__CMD, 0x70092000, 0x0000000000000001 // 240
	, WRITE__CMD, 0x70092000, 0x0000000000000000 // 241
	, RDSPIN_CMD, 0x70092000, 0x0000000000000002, 0x2, 0x1f4 // 242
	, RDnCMP_CMD, 0x70092008, 0x0000000000001e69 // 243
	, RDnCMP_CMD, 0x70092010, 0x8e361a56dec99e23 // 244
	, RDnCMP_CMD, 0x70092018, 0x01860b8dcdbb5031 // 245
	, RDnCMP_CMD, 0x70092020, 0x528e1706d446cad4 // 246
	, RDnCMP_CMD, 0x70092028, 0x20744e64c096b17a // 247
	, WRITE__CMD, 0x70092040, 0xb0023b06fd3122f2 // 248
	, WRITE__CMD, 0x70092048, 0x650c02ff747f7114 // 249
	, WRITE__CMD, 0x70092050, 0x69e831e62331c0dd // 250
	, WRITE__CMD, 0x70092030, 0x0000000000000015 // 251
	, WRITE__CMD, 0x70092000, 0x0000000000000001 // 252
	, WRITE__CMD, 0x70092000, 0x0000000000000000 // 253
	, RDSPIN_CMD, 0x70092000, 0x0000000000000002, 0x2, 0x1f4 // 254
	, RDnCMP_CMD, 0x70092008, 0x0000000000001f30 // 255
	, RDnCMP_CMD, 0x70092010, 0x8e36181f4f60ede4 // 256
	, RDnCMP_CMD, 0x70092018, 0x18f0bc2ccca36d76 // 257
	, RDnCMP_CMD, 0x70092020, 0x8f3a071681c42b94 // 258
	, RDnCMP_CMD, 0x70092028, 0x5e26afd6b2eddbf1 // 259
	, WRITE__CMD, 0x70092040, 0xe7f57201ab6affdc // 260
	, WRITE__CMD, 0x70092048, 0x745e34269393d0ed // 261
	, WRITE__CMD, 0x70092050, 0xd2b014256d9c9b09 // 262
	, WRITE__CMD, 0x70092030, 0x0000000000000016 // 263
	, WRITE__CMD, 0x70092000, 0x0000000000000001 // 264
	, WRITE__CMD, 0x70092000, 0x0000000000000000 // 265
	, RDSPIN_CMD, 0x70092000, 0x0000000000000002, 0x2, 0x1f4 // 266
	, RDnCMP_CMD, 0x70092008, 0x0000000000001f9c // 267
	, RDnCMP_CMD, 0x70092010, 0x8e36193b87b45407 // 268
	, RDnCMP_CMD, 0x70092018, 0x944be7fc4c2f73d5 // 269
	, RDnCMP_CMD, 0x70092020, 0x0cce3602359e5632 // 270
	, RDnCMP_CMD, 0x70092028, 0x6cb146890d11ff22 // 271
	, WRITE__CMD, 0x70092040, 0x2385ace9295a56da // 272
	, WRITE__CMD, 0x70092048, 0xeba9a40130e9f5f8 // 273
	, WRITE__CMD, 0x70092050, 0xf1dfcec94a2c36c8 // 274
	, WRITE__CMD, 0x70092030, 0x0000000000000017 // 275
	, WRITE__CMD, 0x70092000, 0x0000000000000001 // 276
	, WRITE__CMD, 0x70092000, 0x0000000000000000 // 277
	, RDSPIN_CMD, 0x70092000, 0x0000000000000002, 0x2, 0x1f4 // 278
	, RDnCMP_CMD, 0x70092008, 0x000000000000119e // 279
	, RDnCMP_CMD, 0x70092010, 0x8e3619a9e3de08f6 // 280
	, RDnCMP_CMD, 0x70092018, 0x52164a140c697c84 // 281
	, RDnCMP_CMD, 0x70092020, 0x107ee768cc5c5947 // 282
	, RDnCMP_CMD, 0x70092028, 0xcf62afe481c578cf // 283
	, WRITE__CMD, 0x70092040, 0x7a108ed2b3f1a612 // 284
	, WRITE__CMD, 0x70092048, 0xf6faf225d17739c4 // 285
	, WRITE__CMD, 0x70092050, 0x307a49f1a3d3f8de // 286
	, WRITE__CMD, 0x70092030, 0x0000000000000018 // 287
	, WRITE__CMD, 0x70092000, 0x0000000000000001 // 288
	, WRITE__CMD, 0x70092000, 0x0000000000000000 // 289
	, RDSPIN_CMD, 0x70092000, 0x0000000000000002, 0x2, 0x1f4 // 290
	, RDnCMP_CMD, 0x70092008, 0x0000000000001e34 // 291
	, RDnCMP_CMD, 0x70092010, 0x8e3619e0d1eb268e // 292
	, RDnCMP_CMD, 0x70092018, 0xb1389ce02c4a7b2c // 293
	, RDnCMP_CMD, 0x70092020, 0xf1816e4e27df4b76 // 294
	, RDnCMP_CMD, 0x70092028, 0x3f26630b165aa3ed // 295
	, WRITE__CMD, 0x70092040, 0xd6c0d625c77fc5f9 // 296
	, WRITE__CMD, 0x70092048, 0x7be35a30701506e3 // 297
	, WRITE__CMD, 0x70092050, 0x607756e9bd7529f8 // 298
	, WRITE__CMD, 0x70092030, 0x0000000000000019 // 299
	, WRITE__CMD, 0x70092000, 0x0000000000000001 // 300
	, WRITE__CMD, 0x70092000, 0x0000000000000000 // 301
	, RDSPIN_CMD, 0x70092000, 0x0000000000000002, 0x2, 0x1f4 // 302
	, RDnCMP_CMD, 0x70092008, 0x0000000000001f1e // 303
	, RDnCMP_CMD, 0x70092010, 0x8e3619c448f1b1b2 // 304
	, RDnCMP_CMD, 0x70092018, 0xc0aff79a3c5bf8f8 // 305
	, RDnCMP_CMD, 0x70092020, 0x72089edb683db0d0 // 306
	, RDnCMP_CMD, 0x70092028, 0x9acb51ef780c039f // 307
	, WRITE__CMD, 0x70092040, 0x36c9e42ebebac2d6 // 308
	, WRITE__CMD, 0x70092048, 0xe1031c192cf4b1ba // 309
	, WRITE__CMD, 0x70092050, 0xfbb6e919e11820bd // 310
	, WRITE__CMD, 0x70092030, 0x000000000000001a // 311
	, WRITE__CMD, 0x70092000, 0x0000000000000001 // 312
	, WRITE__CMD, 0x70092000, 0x0000000000000000 // 313
	, RDSPIN_CMD, 0x70092000, 0x0000000000000002, 0x2, 0x1f4 // 314
	, RDnCMP_CMD, 0x70092008, 0x0000000000001f8b // 315
	, RDnCMP_CMD, 0x70092010, 0x8e3619d6047cfa2c // 316
	, RDnCMP_CMD, 0x70092018, 0xf864422734533912 // 317
	, RDnCMP_CMD, 0x70092020, 0x76cdb6879f45f5c5 // 318
	, RDnCMP_CMD, 0x70092028, 0x8984f7334525bb00 // 319
	, WRITE__CMD, 0x70092040, 0xadead4cad03c78ca // 320
	, WRITE__CMD, 0x70092048, 0xd4d104074258fb16 // 321
	, WRITE__CMD, 0x70092050, 0x384f690c10db32e6 // 322
	, WRITE__CMD, 0x70092030, 0x000000000000001b // 323
	, WRITE__CMD, 0x70092000, 0x0000000000000001 // 324
	, WRITE__CMD, 0x70092000, 0x0000000000000000 // 325
	, RDSPIN_CMD, 0x70092000, 0x0000000000000002, 0x2, 0x1f4 // 326
	, RDnCMP_CMD, 0x70092008, 0x0000000000001fc1 // 327
	, RDnCMP_CMD, 0x70092010, 0x8e3619df223a5fe3 // 328
	, RDnCMP_CMD, 0x70092018, 0xe40198f9b05759e7 // 329
	, RDnCMP_CMD, 0x70092020, 0xc93a73d041e41c86 // 330
	, RDnCMP_CMD, 0x70092028, 0xdfb13652977357a3 // 331
	, WRITE__CMD, 0x70092040, 0xa8695e347c1a8737 // 332
	, WRITE__CMD, 0x70092048, 0x90951ddd8c808ede // 333
	, WRITE__CMD, 0x70092050, 0x6fd532199f4a5509 // 334
	, WRITE__CMD, 0x70092030, 0x000000000000001c // 335
	, WRITE__CMD, 0x70092000, 0x0000000000000001 // 336
	, WRITE__CMD, 0x70092000, 0x0000000000000000 // 337
	, RDSPIN_CMD, 0x70092000, 0x0000000000000002, 0x2, 0x1f4 // 338
	, RDnCMP_CMD, 0x70092008, 0x0000000000001fe4 // 339
	, RDnCMP_CMD, 0x70092010, 0x8e3619dbb1190d04 // 340
	, RDnCMP_CMD, 0x70092018, 0x6a337596f255699d // 341
	, RDnCMP_CMD, 0x70092020, 0x91b900111db08bb4 // 342
	, RDnCMP_CMD, 0x70092028, 0xcf6db27b689248e4 // 343
	, WRITE__CMD, 0x70092040, 0x8a50e90166c0ab09 // 344
	, WRITE__CMD, 0x70092048, 0xb8d76d294f45f9ef // 345
	, WRITE__CMD, 0x70092050, 0x040c563c9d671606 // 346
	, WRITE__CMD, 0x70092030, 0x000000000000001d // 347
	, WRITE__CMD, 0x70092000, 0x0000000000000001 // 348
	, WRITE__CMD, 0x70092000, 0x0000000000000000 // 349
	, RDSPIN_CMD, 0x70092000, 0x0000000000000002, 0x2, 0x1f4 // 350
	, RDnCMP_CMD, 0x70092008, 0x00000000000012bc // 351
	, RDnCMP_CMD, 0x70092010, 0x8e3619d9f888a477 // 352
	, RDnCMP_CMD, 0x70092018, 0xad2a0321535471a0 // 353
	, RDnCMP_CMD, 0x70092020, 0xacc6f1f632c66f75 // 354
	, RDnCMP_CMD, 0x70092028, 0xb1f34911f4ef8717 // 355
	, WRITE__CMD, 0x70092040, 0xc79334c9f0c71622 // 356
	, WRITE__CMD, 0x70092048, 0xc789c0e6775dedeb // 357
	, WRITE__CMD, 0x70092050, 0x66e46c3b043dc1ca // 358
	, WRITE__CMD, 0x70092030, 0x000000000000001e // 359
	, WRITE__CMD, 0x70092000, 0x0000000000000001 // 360
	, WRITE__CMD, 0x70092000, 0x0000000000000000 // 361
	, RDSPIN_CMD, 0x70092000, 0x0000000000000002, 0x2, 0x1f4 // 362
	, RDnCMP_CMD, 0x70092008, 0x000000000000195a // 363
	, RDnCMP_CMD, 0x70092010, 0x8e3619d8dc4070ce // 364
	, RDnCMP_CMD, 0x70092018, 0x4ea6b87a83d4fdbe // 365
	, RDnCMP_CMD, 0x70092020, 0x5aa3202651f9df08 // 366
	, RDnCMP_CMD, 0x70092028, 0x6403d2646884817a // 367
	, WRITE__CMD, 0x70092040, 0x45676ddca38f251a // 368
	, WRITE__CMD, 0x70092048, 0x117fa9d1bb9a3038 // 369
	, WRITE__CMD, 0x70092050, 0xba7dfa35ea8a73bc // 370
	, WRITE__CMD, 0x70092030, 0x000000000000001f // 371
	, WRITE__CMD, 0x70092000, 0x0000000000000001 // 372
	, WRITE__CMD, 0x70092000, 0x0000000000000000 // 373
	, RDSPIN_CMD, 0x70092000, 0x0000000000000002, 0x2, 0x1f4 // 374
	, RDnCMP_CMD, 0x70092008, 0x0000000000001ca9 // 375
	, RDnCMP_CMD, 0x70092010, 0x8e3619d84e241a92 // 376
	, RDnCMP_CMD, 0x70092018, 0xbf60e5d76b94bbb1 // 377
	, RDnCMP_CMD, 0x70092020, 0x969007f6aba303a3 // 378
	, RDnCMP_CMD, 0x70092028, 0x25dfc5aeedebbd1d // 379
	, WRITE__CMD, 0x70092040, 0x66f9231425be71cc // 380
	, WRITE__CMD, 0x70092048, 0x387f5edc4a64681f // 381
	, WRITE__CMD, 0x70092050, 0x1af428d6639d55d5 // 382
	, WRITE__CMD, 0x70092030, 0x0000000000000020 // 383
	, WRITE__CMD, 0x70092000, 0x0000000000000001 // 384
	, WRITE__CMD, 0x70092000, 0x0000000000000000 // 385
	, RDSPIN_CMD, 0x70092000, 0x0000000000000002, 0x2, 0x1f4 // 386
	, RDnCMP_CMD, 0x70092008, 0x0000000000001e50 // 387
	, RDnCMP_CMD, 0x70092010, 0x8e3619d807162fbc // 388
	, RDnCMP_CMD, 0x70092018, 0xc783cb019fb498b6 // 389
	, RDnCMP_CMD, 0x70092020, 0xac18efeeea1c82aa // 390
	, RDnCMP_CMD, 0x70092028, 0xfb88036aedec0214 // 391
	, WRITE__CMD, 0x70092040, 0x63aee5d3d4448f2a // 392
	, WRITE__CMD, 0x70092048, 0x9dc9c51d0e7fbd02 // 393
	, WRITE__CMD, 0x70092050, 0x5bad5ad216cf2739 // 394
	, WRITE__CMD, 0x70092030, 0x0000000000000021 // 395
	, WRITE__CMD, 0x70092000, 0x0000000000000001 // 396
	, WRITE__CMD, 0x70092000, 0x0000000000000000 // 397
	, RDSPIN_CMD, 0x70092000, 0x0000000000000002, 0x2, 0x1f4 // 398
	, RDnCMP_CMD, 0x70092008, 0x0000000000001f2c // 399
	, RDnCMP_CMD, 0x70092010, 0x8e3619d8238f352b // 400
	, RDnCMP_CMD, 0x70092018, 0xfbf25c6ae5a48935 // 401
	, RDnCMP_CMD, 0x70092020, 0xf1bacca8c4cd691a // 402
	, RDnCMP_CMD, 0x70092028, 0x0f4a9195e056463a // 403
	, WRITE__CMD, 0x70092040, 0x79b5e5dfcc73c7e3 // 404
	, WRITE__CMD, 0x70092048, 0xe1bda5d6447838bf // 405
	, WRITE__CMD, 0x70092050, 0x0e270feaff605700 // 406
	, WRITE__CMD, 0x70092030, 0x0000000000000022 // 407
	, WRITE__CMD, 0x70092000, 0x0000000000000001 // 408
	, WRITE__CMD, 0x70092000, 0x0000000000000000 // 409
	, RDSPIN_CMD, 0x70092000, 0x0000000000000002, 0x2, 0x1f4 // 410
	, RDnCMP_CMD, 0x70092008, 0x0000000000001e5b // 411
	, RDnCMP_CMD, 0x70092010, 0x8e3619d831c3b860 // 412
	, RDnCMP_CMD, 0x70092018, 0x65ca97df58ac81f4 // 413
	, RDnCMP_CMD, 0x70092020, 0xc2c1cba767cf1a47 // 414
	, RDnCMP_CMD, 0x70092028, 0xb33693c0891b5d77 // 415
	, WRITE__CMD, 0x70092040, 0x8df457c7cc3beb12 // 416
	, WRITE__CMD, 0x70092048, 0x52bb82f26e2fc919 // 417
	, WRITE__CMD, 0x70092050, 0xeed468c714ce1f01 // 418
	, WRITE__CMD, 0x70092030, 0x0000000000000023 // 419
	, WRITE__CMD, 0x70092000, 0x0000000000000001 // 420
	, WRITE__CMD, 0x70092000, 0x0000000000000000 // 421
	, RDSPIN_CMD, 0x70092000, 0x0000000000000002, 0x2, 0x1f4 // 422
	, RDnCMP_CMD, 0x70092008, 0x00000000000012e1 // 423
	, RDnCMP_CMD, 0x70092010, 0x8e3619d838e5fec5 // 424
	, RDnCMP_CMD, 0x70092018, 0xaad6f20586288594 // 425
	, RDnCMP_CMD, 0x70092020, 0x0f157319a623ee9f // 426
	, RDnCMP_CMD, 0x70092028, 0x6e0d27d7b2f7fba7 // 427
	, WRITE__CMD, 0x70092040, 0x066ff5336421d4e4 // 428
	, WRITE__CMD, 0x70092048, 0x5457363c1e39af2b // 429
	, WRITE__CMD, 0x70092050, 0x9b980536a9ca64ea // 430
	, WRITE__CMD, 0x70092030, 0x0000000000000024 // 431
	, WRITE__CMD, 0x70092000, 0x0000000000000001 // 432
	, WRITE__CMD, 0x70092000, 0x0000000000000000 // 433
	, RDSPIN_CMD, 0x70092000, 0x0000000000000002, 0x2, 0x1f4 // 434
	, RDnCMP_CMD, 0x70092008, 0x0000000000001974 // 435
	, RDnCMP_CMD, 0x70092010, 0x8e3619d83c76dd97 // 436
	, RDnCMP_CMD, 0x70092018, 0x4d58c0e8e96a87a4 // 437
	, RDnCMP_CMD, 0x70092020, 0x130b81e2fac6dd4b // 438
	, RDnCMP_CMD, 0x70092028, 0xbfcad16dd2602297 // 439
	, WRITE__CMD, 0x70092040, 0x7f3f4ee0c0f588e3 // 440
	, WRITE__CMD, 0x70092048, 0xd1842ccf51cd990c // 441
	, WRITE__CMD, 0x70092050, 0x4ea7e31d19513a02 // 442
	, WRITE__CMD, 0x70092030, 0x0000000000000025 // 443
	, WRITE__CMD, 0x70092000, 0x0000000000000001 // 444
	, WRITE__CMD, 0x70092000, 0x0000000000000000 // 445
	, RDSPIN_CMD, 0x70092000, 0x0000000000000002, 0x2, 0x1f4 // 446
	, RDnCMP_CMD, 0x70092008, 0x0000000000001e5b // 447
	, RDnCMP_CMD, 0x70092010, 0x8e3619d83e3f4c3e // 448
	, RDnCMP_CMD, 0x70092018, 0x3e9fd99e5ecb86bc // 449
	, RDnCMP_CMD, 0x70092020, 0x2faa717f39534402 // 450
	, RDnCMP_CMD, 0x70092028, 0x2c5df83fd96b257f // 451
	, WRITE__CMD, 0x70092040, 0x3ed2650c657378d4 // 452
	, WRITE__CMD, 0x70092048, 0xcbc938c54ede1b00 // 453
	, WRITE__CMD, 0x70092050, 0x3ade0428d95d1d0f // 454
	, WRITE__CMD, 0x70092030, 0x0000000000000001 // 455
	, WRITE__CMD, 0x70092000, 0x0000000000000001 // 456
	, WRITE__CMD, 0x70092000, 0x0000000000000000 // 457
	, RDSPIN_CMD, 0x70092000, 0x0000000000000002, 0x2, 0x1f4 // 458
	, RDnCMP_CMD, 0x70092008, 0x0000000000001907 // 459
	, RDnCMP_CMD, 0x70092010, 0x924110552bd74e7f // 460
	, RDnCMP_CMD, 0x70092018, 0xc62d21cd7f83b3f9 // 461
	, RDnCMP_CMD, 0x70092020, 0xe459de1fc314a865 // 462
	, RDnCMP_CMD, 0x70092028, 0x89b3788b6db9056a // 463
	, WRITE__CMD, 0x70092030, 0x0000000000000000 // 464
	, WRITE__CMD, 0x70092040, 0xe6e728f501ca581d // 465
	, WRITE__CMD, 0x70092048, 0x4a2624baecbc8127 // 466
	, WRITE__CMD, 0x70092050, 0x867a68f9a337892c // 467
	, WRITE__CMD, 0x70092060, 0x00005c22fee52078 // 468
	, WRITE__CMD, 0x70092058, 0x000000002aaab0a3 // 469
	, WRITE__CMD, 0x70092030, 0x0000000000000001 // 470
	, WRITE__CMD, 0x70092000, 0x0000000000000001 // 471
	, WRITE__CMD, 0x70092000, 0x0000000000000000 // 472
	, RDSPIN_CMD, 0x70092000, 0x0000000000000002, 0x2, 0x1f4 // 473
	, RDnCMP_CMD, 0x70092008, 0x0000000000001907 // 474
	, RDnCMP_CMD, 0x70092010, 0x5b01abdf2d263f34 // 475
	, RDnCMP_CMD, 0x70092018, 0x908af5d6c06af7cb // 476
	, RDnCMP_CMD, 0x70092020, 0xa5ab2f4672fb86bb // 477
	, RDnCMP_CMD, 0x70092028, 0x953ea416d6e1530d // 478
	, WRITE__CMD, 0x70092000, 0x0000000000000001 // 479
	, WRITE__CMD, 0x70092000, 0x0000000000000000 // 480
	, RDSPIN_CMD, 0x70092000, 0x0000000000000002, 0x2, 0x1f4 // 481
	, RDnCMP_CMD, 0x70092008, 0x0000000000000527 // 482
	, RDnCMP_CMD, 0x70092010, 0x498fcd2422bd75b0 // 483
	, RDnCMP_CMD, 0x70092018, 0x1abc641906411d0c // 484
	, RDnCMP_CMD, 0x70092020, 0x4bc4a48260f4ee37 // 485
	, RDnCMP_CMD, 0x70092028, 0x54155b6167ed1bbb // 486
	, WRITE__CMD, 0x70092000, 0x0000000000000001 // 487
	, WRITE__CMD, 0x70092000, 0x0000000000000000 // 488
	, RDSPIN_CMD, 0x70092000, 0x0000000000000002, 0x2, 0x1f4 // 489
	, RDnCMP_CMD, 0x70092008, 0x0000000000001289 // 490
	, RDnCMP_CMD, 0x70092010, 0xa6db4d9f3de26e10 // 491
	, RDnCMP_CMD, 0x70092018, 0xc192b5c5c52b67cf // 492
	, RDnCMP_CMD, 0x70092020, 0x752806303d25abfc // 493
	, RDnCMP_CMD, 0x70092028, 0x9bbecb1a02f9842a // 494
	, WRITE__CMD, 0x70092000, 0x0000000000000001 // 495
	, WRITE__CMD, 0x70092000, 0x0000000000000000 // 496
	, RDSPIN_CMD, 0x70092000, 0x0000000000000002, 0x2, 0x1f4 // 497
	, RDnCMP_CMD, 0x70092008, 0x0000000000001ead // 498
	, RDnCMP_CMD, 0x70092010, 0x789b843064ad7170 // 499
	, RDnCMP_CMD, 0x70092018, 0x803c81679ddc92d6 // 500
	, RDnCMP_CMD, 0x70092020, 0x25b9a94a7e0ecdcf // 501
	, RDnCMP_CMD, 0x70092028, 0x5c0e59fdbe0a58d1 // 502
	, WRITE__CMD, 0x70092000, 0x0000000000000001 // 503
	, WRITE__CMD, 0x70092000, 0x0000000000000000 // 504
	, RDSPIN_CMD, 0x70092000, 0x0000000000000002, 0x2, 0x1f4 // 505
	, RDnCMP_CMD, 0x70092008, 0x000000000000022a // 506
	, RDnCMP_CMD, 0x70092010, 0x4faf558a4d150984 // 507
	, RDnCMP_CMD, 0x70092018, 0x023114894462010c // 508
	, RDnCMP_CMD, 0x70092020, 0xbca273af9b8b62b2 // 509
	, RDnCMP_CMD, 0x70092028, 0xe132803575b5e2c9 // 510
	, WRITE__CMD, 0x70092000, 0x0000000000000001 // 511
	, WRITE__CMD, 0x70092000, 0x0000000000000000 // 512
	, RDSPIN_CMD, 0x70092000, 0x0000000000000002, 0x2, 0x1f4 // 513
	, RDnCMP_CMD, 0x70092008, 0x0000000000001647 // 514
	, RDnCMP_CMD, 0x70092010, 0x854261008c44e8b4 // 515
	, RDnCMP_CMD, 0x70092018, 0x6a215b01abdf2d26 // 516
	, RDnCMP_CMD, 0x70092020, 0xaf549ad93da81988 // 517
	, RDnCMP_CMD, 0x70092028, 0x3b5cf436405bda15 // 518
};

#define GPS_2_adrBase 0x0070090000
#define GPS_2_adrSize 0x10000
#define GPS_2_cmdCnt4Single 19
#define GPS_2_totalCommands 518
#endif
