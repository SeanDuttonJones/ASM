#include "operation.hpp"
#include "instructions.hpp"

#include <iostream>

PushIInstruction::PushIInstruction(IContext *context, any value) 
    : Operation(context, OperationType::INSTRUCTION, Opcode::PushI, value)
{}

void PushIInstruction::install() {
    // std::cout << "PushI: installing" << std::endl;
}

void PushIInstruction::execute() {
    // std::cout << "PushI: executing" << std::endl;
    IStackAccess *stackAccessor = context->getStackAccess();
    stackAccessor->push(value);
}