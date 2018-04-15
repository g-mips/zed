#ifndef MIPS_DECODE
#define MIPS_DECODE

/*
  Dependant includes:
  #include <stdint.h>
*/

#define BITS_IN_BYTE 8

// Bits
#define OP_BITS     0xFC000000
#define RS_BITS     0x03E00000
#define RT_BITS     0x001F0000
#define RD_BITS     0x0000F800
#define SHAMT_BITS  0x000007C0
#define FUNCT_BITS  0x0000003F
#define IMM_BITS    0x0000FFFF
#define TARGET_BITS 0x03FFFFFF

// Offset
#define OP_OFFSET     0x1A
#define RS_OFFSET     0x15
#define RT_OFFSET     0x10
#define RD_OFFSET     0x0B
#define SHAMT_OFFSET  0x06
#define FUNCT_OFFSET  0x00
#define IMM_OFFSET    0x00
#define TARGET_OFFSET 0x00

// Get Macros
#define GET_BITS(inst, mask, offset) (((inst) & (mask)) >> (offset))
#define OP_GET(inst) GET_BITS(inst, OP_BITS, OP_OFFSET)
#define RS_GET(inst) GET_BITS(inst, RS_BITS, RS_OFFSET)
#define RT_GET(inst) GET_BITS(inst, RT_BITS, RT_OFFSET)
#define RD_GET(inst) GET_BITS(inst, RD_BITS, RD_OFFSET)
#define SHAMT_GET(inst) GET_BITS(inst, SHAMT_BITS, SHAMT_OFFSET)
#define FUNCT_GET(inst) GET_BITS(inst, FUNCT_BITS, FUNCT_OFFSET)
#define IMM_GET(inst) (int16_t)GET_BITS(inst, IMM_BITS, IMM_OFFSET)
#define TARGET_GET(inst) GET_BITS(inst, TARGET_BITS, TARGET_OFFSET)

// Register Zero
#define R0_STR "$zero"

// Assembler Temporary
#define R1_STR "$at"

// Values
#define R2_STR "$v0"
#define R3_STR "$v1"

// Arguments
#define R4_STR "$a0"
#define R5_STR "$a1"
#define R6_STR "$a2"
#define R7_STR "$a3"

// Temporaries
#define R8_STR "$t0"
#define R9_STR "$t1"
#define R10_STR "$t2"
#define R11_STR "$t3"
#define R12_STR "$t4"
#define R13_STR "$t5"
#define R14_STR "$t6"
#define R15_STR "$t7"

// Saved Values
#define R16_STR "$s0"
#define R17_STR "$s1"
#define R18_STR "$s2"
#define R19_STR "$s3"
#define R20_STR "$s4"
#define R21_STR "$s5"
#define R22_STR "$s6"
#define R23_STR "$s7"

// Temporaries
#define R24_STR "$t8"
#define R25_STR "$t9"

// Reserved for use by the interrupt/trap handler
#define R26_STR "$k0"
#define R27_STR "$k1"

// Global pointer
#define R28_STR "$gp"

// Stack pointer
#define R29_STR "$sp"

// Saved value / Frame pointer
#define R30_STR "$s8/$fp"

// Return Address
#define R31_STR "$ra"

#define MAX_INST_LENGTH 1024

enum instruction_type {
    IMMEDIATE,
    JUMP,
    REGISTER,

    UNSUPPORTED
};

// R -- opcode(6) :: 31-26, rs(5) :: 25-21, rt(5) :: 20-16, rd(5) :: 15-11,
//      shamt(5) :: 10-6, funct(6) :: 5-0
// I -- opcode(6) :: 31-26, rs(5) :: 25-21, rt(5) :: 20-16, imm(16) :: 15-0
// J -- opcode(6) :: 31-26, address(26) :: 25-0
struct mips_inst {
    uint32_t address;
    uint32_t raw_inst;

    uint8_t opcode;

    char inst_format[MAX_INST_LENGTH];

    bool valid;
};

struct mips_inst mips_decode_mips_inst_new(uint32_t raw_inst, uint32_t address);

#endif // MIPS_DECODE
