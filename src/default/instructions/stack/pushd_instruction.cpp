#include "operation.h"
#include "instructions.h"

#include <iostream>

PushDInstruction::PushDInstruction(Opcode opcode, std::any operand)
    : Operation(opcode, operand)
{}

void PushDInstruction::execute(IContext *context) {
    IStackAccess *stackAccessor = context->getStackAccess();
    stackAccessor->push(operand);
}