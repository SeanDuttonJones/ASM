#include "operation.h"
#include "instructions.h"

#include <iostream>

PushFInstruction::PushFInstruction(Opcode opcode, std::any operand)
    : Operation(opcode, operand)
{}

void PushFInstruction::execute(IContext *context) {
    // std::cout << "PushI: executing" << std::endl;
    IStackAccess *stackAccessor = context->getStackAccess();
    stackAccessor->push(operand);
}