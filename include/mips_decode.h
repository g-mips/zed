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
#define IMM_GET(inst) GET_BITS(inst, IMM_BITS, IMM_OFFSET)
#define TARGET_GET(inst) GET_BITS(inst, TARGET_BITS, TARGET_OFFSET)

enum instruction_type {
    IMMEDIATE,
    JUMP,
    REGISTER,

    UNSUPPORTED
};

// Immediate
struct i_instruction {
    uint8_t op;   // operation code
    uint8_t rs;   // source register specifier
    uint8_t rt;   // target (source/destination) or branch condition
    uint16_t imm; // immediate, branch displacement or address

    uint32_t address;
};

// Jump
struct j_instruction {
    uint8_t op;      // operation code
    uint32_t target; // 26-bit jump target address

    uint32_t address;
};

// Register
struct r_instruction {
    uint8_t op;    // operation code
    uint8_t rs;    // source register specifier
    uint8_t rt;    // target (source/destination) or branch condition
    uint8_t rd;    // destination register specifier
    uint8_t shamt; // shift amount
    uint8_t funct; // function field

    uint32_t address;
};

enum instruction_type mips_decode_instruction_type(uint32_t instruction);
struct r_instruction mips_decode_new_r_instruction(uint32_t raw_inst, uint32_t address);

#endif // MIPS_DECODE
