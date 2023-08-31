#include "instructions.h"

StoreCInstruction::StoreCInstruction(Opcode opcode, std::any operand)
    : Operation(opcode, operand)
{}

void StoreCInstruction::execute(IContext *context) {
    IStackAccess *stackAccessor = context->getStackAccess();
    IMemoryAccess *memoryAccessor = context->getMemoryAccess();

    char value = (char)(std::any_cast<int>(stackAccessor->top()));
    stackAccessor->pop();
    int memoryLocation = std::any_cast<int>(stackAccessor->top());
    stackAccessor->pop();

    memoryAccessor->writeChar(memoryLocation, value);
}