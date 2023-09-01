#include "instructions.h"

#include <iostream>

PopPCInstruction::PopPCInstruction(Opcode opcode, std::any operand) 
    : Operation(opcode, operand)
{}

void PopPCInstruction::execute(IContext *context) {
    IStackAccess *stackAccessor = context->getStackAccess();
    IPCAccess *pcAccess = context->getPCAccess();

    std::any operand = stackAccessor->top();
    stackAccessor->pop();

    if(TypeTools::getType(std::type_index(operand.type())) != Type::INT) {
        std::cerr << "Invalid operand for instruction PopPC" << std::endl;
        exit(1);
    }

    int npc = std::any_cast<int>(operand);
    pcAccess->set(npc);
}