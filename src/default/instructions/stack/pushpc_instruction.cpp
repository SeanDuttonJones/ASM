#include "operation.h"
#include "instructions.h"

#include <iostream>

PushPCInstruction::PushPCInstruction(Opcode opcode, std::any operand)
    : Operation(opcode, operand)
{}

void PushPCInstruction::execute(IContext *context) {
    IStackAccess *stackAccessor = context->getStackAccess();
    IPCAccess *pcAccessor = context->getPCAccess();

    int pc = pcAccessor->get();
    stackAccessor->push(pc);
}