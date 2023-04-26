#include "init.h"
#include "attacks.h"
#include "magic.h"
#include "board.h"


const Bitboard pawn_attacks[2][64] =
{ {
0x0000000000000000ULL, 0x0000000000000000ULL, 0x0000000000000000ULL, 0x0000000000000000ULL,
0x0000000000000000ULL, 0x0000000000000000ULL, 0x0000000000000000ULL, 0x0000000000000000ULL,
0x0000000000000002ULL, 0x0000000000000005ULL, 0x000000000000000aULL, 0x0000000000000014ULL,
0x0000000000000028ULL, 0x0000000000000050ULL, 0x00000000000000a0ULL, 0x0000000000000040ULL,
0x0000000000000200ULL, 0x0000000000000500ULL, 0x0000000000000a00ULL, 0x0000000000001400ULL,
0x0000000000002800ULL, 0x0000000000005000ULL, 0x000000000000a000ULL, 0x0000000000004000ULL,
0x0000000000020000ULL, 0x0000000000050000ULL, 0x00000000000a0000ULL, 0x0000000000140000ULL,
0x0000000000280000ULL, 0x0000000000500000ULL, 0x0000000000a00000ULL, 0x0000000000400000ULL,
0x0000000002000000ULL, 0x0000000005000000ULL, 0x000000000a000000ULL, 0x0000000014000000ULL,
0x0000000028000000ULL, 0x0000000050000000ULL, 0x00000000a0000000ULL, 0x0000000040000000ULL,
0x0000000200000000ULL, 0x0000000500000000ULL, 0x0000000a00000000ULL, 0x0000001400000000ULL,
0x0000002800000000ULL, 0x0000005000000000ULL, 0x000000a000000000ULL, 0x0000004000000000ULL,
0x0000020000000000ULL, 0x0000050000000000ULL, 0x00000a0000000000ULL, 0x0000140000000000ULL,
0x0000280000000000ULL, 0x0000500000000000ULL, 0x0000a00000000000ULL, 0x0000400000000000ULL,
0x0002000000000000ULL, 0x0005000000000000ULL, 0x000a000000000000ULL, 0x0014000000000000ULL,
0x0028000000000000ULL, 0x0050000000000000ULL, 0x00a0000000000000ULL, 0x0040000000000000ULL,
}, {
0x0000000000000200ULL, 0x0000000000000500ULL, 0x0000000000000a00ULL, 0x0000000000001400ULL,
0x0000000000002800ULL, 0x0000000000005000ULL, 0x000000000000a000ULL, 0x0000000000004000ULL,
0x0000000000020000ULL, 0x0000000000050000ULL, 0x00000000000a0000ULL, 0x0000000000140000ULL,
0x0000000000280000ULL, 0x0000000000500000ULL, 0x0000000000a00000ULL, 0x0000000000400000ULL,
0x0000000002000000ULL, 0x0000000005000000ULL, 0x000000000a000000ULL, 0x0000000014000000ULL,
0x0000000028000000ULL, 0x0000000050000000ULL, 0x00000000a0000000ULL, 0x0000000040000000ULL,
0x0000000200000000ULL, 0x0000000500000000ULL, 0x0000000a00000000ULL, 0x0000001400000000ULL,
0x0000002800000000ULL, 0x0000005000000000ULL, 0x000000a000000000ULL, 0x0000004000000000ULL,
0x0000020000000000ULL, 0x0000050000000000ULL, 0x00000a0000000000ULL, 0x0000140000000000ULL,
0x0000280000000000ULL, 0x0000500000000000ULL, 0x0000a00000000000ULL, 0x0000400000000000ULL,
0x0002000000000000ULL, 0x0005000000000000ULL, 0x000a000000000000ULL, 0x0014000000000000ULL,
0x0028000000000000ULL, 0x0050000000000000ULL, 0x00a0000000000000ULL, 0x0040000000000000ULL,
0x0200000000000000ULL, 0x0500000000000000ULL, 0x0a00000000000000ULL, 0x1400000000000000ULL,
0x2800000000000000ULL, 0x5000000000000000ULL, 0xa000000000000000ULL, 0x4000000000000000ULL,
0x0000000000000000ULL, 0x0000000000000000ULL, 0x0000000000000000ULL, 0x0000000000000000ULL,
0x0000000000000000ULL, 0x0000000000000000ULL, 0x0000000000000000ULL, 0x0000000000000000ULL
} };


const Bitboard knight_attacks[64] =
{
0x0000000000020400ULL, 0x0000000000050800ULL, 0x00000000000a1100ULL, 0x0000000000142200ULL,
0x0000000000284400ULL, 0x0000000000508800ULL, 0x0000000000a01000ULL, 0x0000000000402000ULL,
0x0000000002040004ULL, 0x0000000005080008ULL, 0x000000000a110011ULL, 0x0000000014220022ULL,
0x0000000028440044ULL, 0x0000000050880088ULL, 0x00000000a0100010ULL, 0x0000000040200020ULL,
0x0000000204000402ULL, 0x0000000508000805ULL, 0x0000000a1100110aULL, 0x0000001422002214ULL,
0x0000002844004428ULL, 0x0000005088008850ULL, 0x000000a0100010a0ULL, 0x0000004020002040ULL,
0x0000020400040200ULL, 0x0000050800080500ULL, 0x00000a1100110a00ULL, 0x0000142200221400ULL,
0x0000284400442800ULL, 0x0000508800885000ULL, 0x0000a0100010a000ULL, 0x0000402000204000ULL,
0x0002040004020000ULL, 0x0005080008050000ULL, 0x000a1100110a0000ULL, 0x0014220022140000ULL,
0x0028440044280000ULL, 0x0050880088500000ULL, 0x00a0100010a00000ULL, 0x0040200020400000ULL,
0x0204000402000000ULL, 0x0508000805000000ULL, 0x0a1100110a000000ULL, 0x1422002214000000ULL,
0x2844004428000000ULL, 0x5088008850000000ULL, 0xa0100010a0000000ULL, 0x4020002040000000ULL,
0x0400040200000000ULL, 0x0800080500000000ULL, 0x1100110a00000000ULL, 0x2200221400000000ULL,
0x4400442800000000ULL, 0x8800885000000000ULL, 0x100010a000000000ULL, 0x2000204000000000ULL,
0x0004020000000000ULL, 0x0008050000000000ULL, 0x00110a0000000000ULL, 0x0022140000000000ULL,
0x0044280000000000ULL, 0x0088500000000000ULL, 0x0010a00000000000ULL, 0x0020400000000000ULL
};


const Bitboard king_attacks[64] =
{
0x0000000000000302ULL, 0x0000000000000705ULL, 0x0000000000000e0aULL, 0x0000000000001c14ULL,
0x0000000000003828ULL, 0x0000000000007050ULL, 0x000000000000e0a0ULL, 0x000000000000c040ULL,
0x0000000000030203ULL, 0x0000000000070507ULL, 0x00000000000e0a0eULL, 0x00000000001c141cULL,
0x0000000000382838ULL, 0x0000000000705070ULL, 0x0000000000e0a0e0ULL, 0x0000000000c040c0ULL,
0x0000000003020300ULL, 0x0000000007050700ULL, 0x000000000e0a0e00ULL, 0x000000001c141c00ULL,
0x0000000038283800ULL, 0x0000000070507000ULL, 0x00000000e0a0e000ULL, 0x00000000c040c000ULL,
0x0000000302030000ULL, 0x0000000705070000ULL, 0x0000000e0a0e0000ULL, 0x0000001c141c0000ULL,
0x0000003828380000ULL, 0x0000007050700000ULL, 0x000000e0a0e00000ULL, 0x000000c040c00000ULL,
0x0000030203000000ULL, 0x0000070507000000ULL, 0x00000e0a0e000000ULL, 0x00001c141c000000ULL,
0x0000382838000000ULL, 0x0000705070000000ULL, 0x0000e0a0e0000000ULL, 0x0000c040c0000000ULL,
0x0003020300000000ULL, 0x0007050700000000ULL, 0x000e0a0e00000000ULL, 0x001c141c00000000ULL,
0x0038283800000000ULL, 0x0070507000000000ULL, 0x00e0a0e000000000ULL, 0x00c040c000000000ULL,
0x0302030000000000ULL, 0x0705070000000000ULL, 0x0e0a0e0000000000ULL, 0x1c141c0000000000ULL,
0x3828380000000000ULL, 0x7050700000000000ULL, 0xe0a0e00000000000ULL, 0xc040c00000000000ULL,
0x0203000000000000ULL, 0x0507000000000000ULL, 0x0a0e000000000000ULL, 0x141c000000000000ULL,
0x2838000000000000ULL, 0x5070000000000000ULL, 0xa0e0000000000000ULL, 0x40c0000000000000ULL
};



const Bitboard bishop_occupancy[64] =
{
0x0040201008040200ULL, 0x0000402010080400ULL, 0x0000004020100a00ULL, 0x0000000040221400ULL,
0x0000000002442800ULL, 0x0000000204085000ULL, 0x0000020408102000ULL, 0x0002040810204000ULL,
0x0020100804020000ULL, 0x0040201008040000ULL, 0x00004020100a0000ULL, 0x0000004022140000ULL,
0x0000000244280000ULL, 0x0000020408500000ULL, 0x0002040810200000ULL, 0x0004081020400000ULL,
0x0010080402000200ULL, 0x0020100804000400ULL, 0x004020100a000a00ULL, 0x0000402214001400ULL,
0x0000024428002800ULL, 0x0002040850005000ULL, 0x0004081020002000ULL, 0x0008102040004000ULL,
0x0008040200020400ULL, 0x0010080400040800ULL, 0x0020100a000a1000ULL, 0x0040221400142200ULL,
0x0002442800284400ULL, 0x0004085000500800ULL, 0x0008102000201000ULL, 0x0010204000402000ULL,
0x0004020002040800ULL, 0x0008040004081000ULL, 0x00100a000a102000ULL, 0x0022140014224000ULL,
0x0044280028440200ULL, 0x0008500050080400ULL, 0x0010200020100800ULL, 0x0020400040201000ULL,
0x0002000204081000ULL, 0x0004000408102000ULL, 0x000a000a10204000ULL, 0x0014001422400000ULL,
0x0028002844020000ULL, 0x0050005008040200ULL, 0x0020002010080400ULL, 0x0040004020100800ULL,
0x0000020408102000ULL, 0x0000040810204000ULL, 0x00000a1020400000ULL, 0x0000142240000000ULL,
0x0000284402000000ULL, 0x0000500804020000ULL, 0x0000201008040200ULL, 0x0000402010080400ULL,
0x0002040810204000ULL, 0x0004081020400000ULL, 0x000a102040000000ULL, 0x0014224000000000ULL,
0x0028440200000000ULL, 0x0050080402000000ULL, 0x0020100804020000LL, 0x0040201008040200ULL
};

const Bitboard rook_occupancy[64] =
{
0x000101010101017eULL, 0x000202020202027cULL, 0x000404040404047aULL, 0x0008080808080876ULL,
0x001010101010106eULL, 0x002020202020205eULL, 0x004040404040403eULL, 0x008080808080807eULL,
0x0001010101017e00ULL, 0x0002020202027c00ULL, 0x0004040404047a00ULL, 0x0008080808087600ULL,
0x0010101010106e00ULL, 0x0020202020205e00ULL, 0x0040404040403e00ULL, 0x0080808080807e00ULL,
0x00010101017e0100ULL, 0x00020202027c0200ULL, 0x00040404047a0400ULL, 0x0008080808760800ULL,
0x00101010106e1000ULL, 0x00202020205e2000ULL, 0x00404040403e4000ULL, 0x00808080807e8000ULL,
0x000101017e010100ULL, 0x000202027c020200ULL, 0x000404047a040400ULL, 0x0008080876080800ULL,
0x001010106e101000ULL, 0x002020205e202000ULL, 0x004040403e404000ULL, 0x008080807e808000ULL,
0x0001017e01010100ULL, 0x0002027c02020200ULL, 0x0004047a04040400ULL, 0x0008087608080800ULL,
0x0010106e10101000ULL, 0x0020205e20202000ULL, 0x0040403e40404000ULL, 0x0080807e80808000ULL,
0x00017e0101010100ULL, 0x00027c0202020200ULL, 0x00047a0404040400ULL, 0x0008760808080800ULL,
0x00106e1010101000ULL, 0x00205e2020202000ULL, 0x00403e4040404000ULL, 0x00807e8080808000ULL,
0x007e010101010100ULL, 0x007c020202020200ULL, 0x007a040404040400ULL, 0x0076080808080800ULL,
0x006e101010101000ULL, 0x005e202020202000ULL, 0x003e404040404000ULL, 0x007e808080808000ULL,
0x7e01010101010100ULL, 0x7c02020202020200ULL, 0x7a04040404040400ULL, 0x7608080808080800ULL,
0x6e10101010101000ULL, 0x5e20202020202000ULL, 0x3e40404040404000ULL, 0x7e80808080808000ULL
};



const int bishop_relevant_occupancy[64] = {
	6, 5, 5, 5, 5, 5, 5, 6,
	5, 5, 5, 5, 5, 5, 5, 5,
	5, 5, 7, 7, 7, 7, 5, 5,
	5, 5, 7, 9, 9, 7, 5, 5,
	5, 5, 7, 9, 9, 7, 5, 5,
	5, 5, 7, 7, 7, 7, 5, 5,
	5, 5, 5, 5, 5, 5, 5, 5,
	6, 5, 5, 5, 5, 5, 5, 6
};


const int rook_relevant_occupancy[64] = {
	12, 11, 11, 11, 11, 11, 11, 12,
	11, 10, 10, 10, 10, 10, 10, 11,
	11, 10, 10, 10, 10, 10, 10, 11,
	11, 10, 10, 10, 10, 10, 10, 11,
	11, 10, 10, 10, 10, 10, 10, 11,
	11, 10, 10, 10, 10, 10, 10, 11,
	11, 10, 10, 10, 10, 10, 10, 11,
	12, 11, 11, 11, 11, 11, 11, 12
};




void InitAll()
{
	init_bitboards();
	init_sliders_attacks(BISHOP);
	init_sliders_attacks(ROOK);


}


























