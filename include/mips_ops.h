#ifndef MIPS_OPS
#define MIPS_OPS

/********** Main CPU Instruction **********/
/**** ENCODED BY OP ****/
// Says thats opcode is define elsewhere
#define SPECIAL 0x00
#define REGIMM  0x01
#define COP0    0x10
#define COP1    0x11

// 0x02 - 0x0F
#define J     0x02 // Jump
#define JAL   0x03 // Jump And Link
#define BEQ   0x04 // Branch On Equal
#define BNE   0x05 // Branch if Not Equals
#define BLEZ  0x06 // Branch On Less Than Or Equal To Zero
#define BGTZ  0x07 // Branch On Greater Than Zero
#define ADDI  0x08 // Add Immediate
#define ADDIU 0x09 // Add Immediate Unsigned
#define SLTI  0x0A // Set On Less Than Immediate
#define SLTIU 0x0B // Set On Less Than Immediate Unsigned
#define ANDI  0x0C // AND Immediate
#define ORI   0x0D // OR Immediate
#define XROI  0x0E // Exclusive OR Immediate
#define LUI   0x0F // Load Upper Immediate

// 0x14 - 0x17
#define BEQL  0x14 // Branch On Equal Likely
#define BNEL  0x15 // Branch On Not Equal Likely
#define BLEZL 0x16 // Branch On Less Than Or Equal To Zero Likely
#define BGTZL 0x17 // Branch On Greater Than Zero Likely

// 0x18 - 0x1B
#define DADDI  0x18
#define DADDIU 0x19
#define LDL    0x1A
#define LDR    0x1B

// 0x20 - 0x3A
#define LB    0x20 // Load Byte
#define LH    0x21 // Load Halfword
#define LWL   0x22 // Load Word Left
#define LW    0x23 // Load Word
#define LBU   0x24 // Load Byte Unsigned
#define LHU   0x25 // Load Halfword Unsigned
#define LWR   0x26 // Load Word Right
#define LWU   0x27 // Load Word Unsigned
#define SB    0x28 // Store Byte
#define SH    0x29 // Store Halfword
#define SWL   0x2A // Store Word Left
#define SW    0x2B // Store Word
#define SDL   0x2C
#define SDR   0x2D
#define SWR   0x2E // Store Word Right
#define CACHE 0x2F // Cache Operation
#define LL    0x30 // Load Linked
#define LWC1  0x31 // Load Word To Coprocessor 1
//#define LWC2  0x32 // Load Word To Coprocessor 2
//#define PREF  0x33
#define LLD   0x34
#define LDC1  0x35 // Load Doubleword To Coprocessor 1
#define LDC2  0x36 // Load Doubleword To Coprocessor 2
#define LD    0x37
#define SC    0x38 // Store Conditional
#define SWC1  0x39 // Store Word From Coprocessor 1
//#define SWC2  0x3A // Store Word From Coprocessor 2

// 0x3D - 0x3E
#define SCD   0x3C
#define SDC1  0x3D // Store Doubleword To Coprocessor 1
#define SDC2  0x3E // Store Doubleword To Coprocessor 2
#define SD    0x3F

/**** ENCODED BY FUNCT (OP == 000000) ****/
#define ADD  0x20  // Add Word
#define ADDU 0x21
#define SUB  0x22
#define SUBU 0x23
#define AND  0x24
#define OR   0x25
#define XOR  0x26  // Exclusive OR Immediate
#define NOR  0x27

/**** INSTRUCTION STRINGS ****/
#define ADDI_STR "addi"
#define ANDI_STR "andi"
#define LW_STR   "lw"
#define SW_STR   "sw"
#define ADD_STR  "add"
#define XOR_STR  "xor"
#define BNE_STR  "bne"

#endif // MIPS_OPS
