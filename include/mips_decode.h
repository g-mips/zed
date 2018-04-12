#ifndef MIPS_DECODE
#define MIPS_DECODE

// Immediate
struct i_instruction {
    unsigned int op  :  6; // operation code
    unsigned int rs  :  5; // source register specifier
    unsigned int rt  :  5; // target (source/destination) or branch condition
    unsigned int imm : 16; // immediate, branch displacement or address
};

// Jump
struct j_instruction {
    unsigned int op     :  6; // operation code
    unsigned int target : 26; // 26-bit jump target address
};

// Register
struct r_instruction {
    unsigned int op    : 6; // operation code
    unsigned int rs    : 5; // source register specifier
    unsigned int rt    : 5; // target (source/destination) or branch condition
    unsigned int rd    : 5; // destination register specifier
    unsigned int shamt : 5; // shift amount
    unsigned int funct : 6; // function field
};

#endif // MIPS_DECODE
