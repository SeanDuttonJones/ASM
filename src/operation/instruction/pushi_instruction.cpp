#include "operation.hpp"
#include "instructions.hpp"

#include <iostream>

PushIInstruction::PushIInstruction(Asm &stackMachine, any value) 
    : Operation(stackMachine, OperationType::INSTRUCTION, Opcode::PushI, value)
{}

void PushIInstruction::install() {
    std::cout << "PushI: installing" << std::endl;
}

void PushIInstruction::execute() {
    std::cout << "PushI: executing" << std::endl;
}