#include "instructions.h"

StoreFInstruction::StoreFInstruction(Opcode opcode, std::any operand)
    : Operation(opcode, operand)
{}

void StoreFInstruction::execute(IContext *context) {
    IStackAccess *stackAccessor = context->getStackAccess();
    IMemoryAccess *memoryAccessor = context->getMemoryAccess();

    double value = std::any_cast<double>(stackAccessor->top());
    stackAccessor->pop();
    int memoryLocation = std::any_cast<int>(stackAccessor->top());
    stackAccessor->pop();

    memoryAccessor->writeDouble(memoryLocation, value);
}