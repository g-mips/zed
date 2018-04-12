#ifndef MIPS_DECODE
#define MIPS_DECODE

/*
  Dependant includes:
  #include <stdint.h>
*/

enum instruction_type {
    IMMEDIATE,
    JUMP,
    REGISTER
};

// Immediate
struct i_instruction {
    uint8_t op;   // operation code
    uint8_t rs;   // source register specifier
    uint8_t rt;   // target (source/destination) or branch condition
    uint16_t imm; // immediate, branch displacement or address
};

// Jump
struct j_instruction {
    uint8_t op;      // operation code
    uint32_t target; // 26-bit jump target address
};

// Register
struct r_instruction {
    uint8_t op;    // operation code
    uint8_t rs;    // source register specifier
    uint8_t rt;    // target (source/destination) or branch condition
    uint8_t rd;    // destination register specifier
    uint8_t shamt; // shift amount
    uint8_t funct; // function field
};

enum instruction_type mips_decode_instruction_type(uint32_t instruction);

#endif // MIPS_DECODE
