#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#include "mips_decode.h"
#include "mips_ops.h"

static char * _mips_decode_get_reg_str(uint8_t reg)
{
    switch (reg)
    {
    case 0:
        return R0_STR;
    case 1:
        return R1_STR;
    case 2:
        return R2_STR;
    case 3:
        return R3_STR;
    case 4:
        return R4_STR;
    case 5:
        return R5_STR;
    case 6:
        return R6_STR;
    case 7:
        return R7_STR;
    case 8:
        return R8_STR;
    case 9:
        return R9_STR;
    case 10:
        return R10_STR;
    case 11:
        return R11_STR;
    case 12:
        return R12_STR;
    case 13:
        return R13_STR;
    case 14:
        return R14_STR;
    case 15:
        return R15_STR;
    case 16:
        return R16_STR;
    case 17:
        return R17_STR;
    case 18:
        return R18_STR;
    case 19:
        return R19_STR;
    case 20:
        return R20_STR;
    case 21:
        return R21_STR;
    case 22:
        return R22_STR;
    case 23:
        return R23_STR;
    case 24:
        return R24_STR;
    case 25:
        return R25_STR;
    case 26:
        return R26_STR;
    case 27:
        return R27_STR;
    case 28:
        return R28_STR;
    case 29:
        return R29_STR;
    case 30:
        return R30_STR;
    case 31:
        return R31_STR;
    default:
        return "INVALID";
    }
}
#define GET_REG_STR(reg) _mips_decode_get_reg_str(reg)

static char * _mips_decode_get_op_str(uint8_t op)
{
    switch (op)
    {
    case ADDI:
        return ADDI_STR;
    case ADD:
        return ADD_STR;
    case ANDI:
        return ANDI_STR;
    case BLTZ:
        return BLTZ_STR;
    case BNE:
        return BNE_STR;
    case LW:
        return LW_STR;
    case SW:
        return SW_STR;
    case XOR:
        return XOR_STR;
    default:
        return "INVALID";
    }
}
#define GET_OP_STR(op) _mips_decode_get_op_str(op)

static uint8_t _mips_decode_get_opcode(uint32_t inst)
{
    switch (OP_GET(inst))
    {
    case SPECIAL:
        return FUNCT_GET(inst);
    case REGIMM:
        return RT_GET(inst);
    case COP0:
    case COP1:
        return INV_OP; // Unimplemented
    default:
        return OP_GET(inst);
    }
}
#define OPCODE_GET(inst) _mips_decode_get_opcode(inst)

static void _mips_decode_set_inst_format(struct mips_inst *inst)
{
    if (inst == NULL)
    {
        return;
    }

    char temp_string[MAX_INST_LENGTH] = "";

    switch (OP_GET(inst->raw_inst))
    {
    case SPECIAL:
        switch (inst->opcode)
        {
            // Register instruction format 1
        case ADD:
        case XOR:
            snprintf(temp_string, MAX_INST_LENGTH, "0x%012X : %08X : %s %s, %s, %s",
                     inst->address, inst->raw_inst, GET_OP_STR(inst->opcode),
                     GET_REG_STR(RD_GET(inst->raw_inst)),
                     GET_REG_STR(RS_GET(inst->raw_inst)),
                     GET_REG_STR(RT_GET(inst->raw_inst)));
            break;
        }
        break;
    case COP0:
    case COP1:
        break;
    case REGIMM:
        switch (inst->opcode)
        {
            // Immediate instruction format 3
        case BLTZ:
            snprintf(temp_string, MAX_INST_LENGTH, "0x%012X : %08X : %s %s, %d",
                     inst->address, inst->raw_inst, GET_OP_STR(inst->opcode),
                     GET_REG_STR(RS_GET(inst->raw_inst)), IMM_GET(inst->raw_inst));
            break;
        }
        break;
    default:
        switch (inst->opcode)
        {
            // Immediate instruction format 1
        case SW:
        case LW:
            snprintf(temp_string, MAX_INST_LENGTH, "0x%012X : %08X : %s %s, %d(%s)",
                     inst->address, inst->raw_inst, GET_OP_STR(inst->opcode),
                     GET_REG_STR(RT_GET(inst->raw_inst)), IMM_GET(inst->raw_inst),
                     GET_REG_STR(RS_GET(inst->raw_inst)));
            break;
            // Immediate instruction format 2
        case ADDI:
        case ANDI:
        case BNE:
            snprintf(temp_string, MAX_INST_LENGTH, "0x%012X : %08X : %s %s, %s, %d",
                     inst->address, inst->raw_inst, GET_OP_STR(inst->opcode),
                     GET_REG_STR(RT_GET(inst->raw_inst)),
                     GET_REG_STR(RS_GET(inst->raw_inst)), IMM_GET(inst->raw_inst));
            break;
        }
        break;
    }

    memset(inst->inst_format, '\0', MAX_INST_LENGTH);
    strncpy(inst->inst_format, temp_string, strlen(temp_string));
}
#define INST_FORMAT_SET(inst) _mips_decode_set_inst_format(inst)

struct mips_inst mips_decode_mips_inst_new(uint32_t raw_inst, uint32_t address)
{
    struct mips_inst inst = {
        .address = address, .raw_inst = raw_inst, .opcode = 0
    };

    inst.opcode = OPCODE_GET(inst.raw_inst);
    INST_FORMAT_SET(&inst);
    inst.valid = true;

    if (inst.opcode == INV_OP || strcmp(inst.inst_format, "") == 0)
    {
        inst.valid = false;
    }

    return inst;
}
