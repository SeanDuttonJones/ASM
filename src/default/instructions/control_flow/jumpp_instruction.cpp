#include "operation.h"
#include "instructions.h"

#include <iostream>

JumpPInstruction::JumpPInstruction(Opcode opcode, std::any operand)
    : Operation(opcode, operand)
{}

void JumpPInstruction::execute(IContext *context) {
    IStackAccess *stackAccessor = context->getStackAccess();
    IPCAccess *pcAccessor = context->getPCAccess();

    if(stackAccessor->size() == 0) {
        std::cerr << "Not enough operands on the stack for instruction JumpP\n" << std::endl;
        exit(1);
    }

    std::any operand1 = stackAccessor->top();
    stackAccessor->pop();

    if(TypeTools::getType(std::type_index(operand1.type())) != Type::INT) {
        std::cerr << "Invalid operand for instruction JumpP\n" << std::endl;
        exit(1);
    }

    int value = std::any_cast<int>(operand1);

    if(value > 0) {
        unsigned int npc = std::any_cast<unsigned int>(operand);
        pcAccessor->set(npc);
    }
}