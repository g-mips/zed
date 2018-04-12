#include <stdint.h>
#include <stdio.h>

#include "mips_decode.h"
#include "mips_ops.h"

struct r_instruction mips_decode_new_r_instruction(uint32_t raw_inst, uint32_t address)
{
    struct r_instruction inst;

    inst.op = OP_GET(raw_inst);
    inst.rs = RS_GET(raw_inst);
    inst.rt = RT_GET(raw_inst);
    inst.rd = RD_GET(raw_inst);
    inst.shamt = SHAMT_GET(raw_inst);
    inst.funct = FUNCT_GET(raw_inst);

    inst.address = address;

    return inst;
}

enum instruction_type mips_decode_instruction_type(uint32_t raw_inst)
{
    uint8_t opcode = (uint8_t)OP_GET(raw_inst);
    enum instruction_type type = UNSUPPORTED;

    // Is it a register type?
    if (opcode == 0)
    {
        opcode = (uint8_t)FUNCT_GET(raw_inst);
        switch (opcode)
        {
        case ADD:
        case SLLV:
            type = REGISTER;
            break;
        default:
            type = UNSUPPORTED;
            break;
        }
    }
    else
    {
        switch (opcode)
        {
        case XORI:
            type = IMMEDIATE;
            break;
        default:
            type = UNSUPPORTED;
        }
    }

    return type;
}
