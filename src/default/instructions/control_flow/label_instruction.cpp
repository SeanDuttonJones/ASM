#include "operation.h"
#include "instructions.h"

LabelInstruction::LabelInstruction(Opcode opcode, std::any operand)
    : Operation(opcode, operand)
{}

void LabelInstruction::execute(IContext *context) {}