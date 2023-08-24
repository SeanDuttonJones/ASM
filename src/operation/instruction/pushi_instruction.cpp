#include "operation.hpp"
#include "instructions.hpp"

#include <iostream>

PushIInstruction::PushIInstruction(std::stack<std::any> *stack, any value) 
    : Operation(stack, OperationType::INSTRUCTION, Opcode::PushI, value)
{}

void PushIInstruction::install() {
    // std::cout << "PushI: installing" << std::endl;
}

void PushIInstruction::execute() {
    // std::cout << "PushI: executing" << std::endl;
}