#include "operation.h"
#include "instructions.h"

#include <iostream>

JumpInstruction::JumpInstruction(Opcode opcode, std::any operand)
    : Operation(opcode, operand)
{}

void JumpInstruction::execute(IContext *context) {
    IStackAccess *stackAccessor = context->getStackAccess();
    IPCAccess *pcAccessor = context->getPCAccess();

    unsigned int npc = std::any_cast<unsigned int>(operand);
    pcAccessor->set(npc);
}