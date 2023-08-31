#include "instructions.h"

PopInstruction::PopInstruction(Opcode opcode, std::any operand) 
    : Operation(opcode, operand)
{}

void PopInstruction::execute(IContext *context) {
    IStackAccess *stackAccessor = context->getStackAccess();

    stackAccessor->pop();
}