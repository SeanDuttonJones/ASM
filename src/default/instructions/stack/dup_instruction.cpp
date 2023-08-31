#include "instructions.h"

DupInstruction::DupInstruction(Opcode opcode, std::any operand) 
    : Operation(opcode, operand)
{}

void DupInstruction::execute(IContext *context) {
    IStackAccess *stackAccessor = context->getStackAccess();

    stackAccessor->push(stackAccessor->top());
}