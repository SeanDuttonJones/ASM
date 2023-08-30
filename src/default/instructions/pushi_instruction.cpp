#include "operation.h"
#include "instructions.hpp"

#include <iostream>

PushIInstruction::PushIInstruction(Opcode opcode, std::any operand)
    : Operation(opcode, operand)
{}

void PushIInstruction::execute(IContext *context) {
    // std::cout << "PushI: executing" << std::endl;
    IStackAccess *stackAccessor = context->getStackAccess();
    stackAccessor->push(operand);
}