#include "instructions.h"

ExchInstruction::ExchInstruction(Opcode opcode, std::any operand) 
    : Operation(opcode, operand)
{}

void ExchInstruction::execute(IContext *context) {
    IStackAccess *stackAccessor = context->getStackAccess();

    std::any b = stackAccessor->top();
    stackAccessor->pop();
    std::any a = stackAccessor->top();
    stackAccessor->pop();

    stackAccessor->push(b);
    stackAccessor->push(a);
}