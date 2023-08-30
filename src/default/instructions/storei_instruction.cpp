#include "instructions.h"

StoreIInstruction::StoreIInstruction(Opcode opcode, std::any operand)
    : Operation(opcode, operand)
{}

void StoreIInstruction::execute(IContext *context) {
    IStackAccess *stackAccessor = context->getStackAccess();
    IMemoryAccess *memoryAccessor = context->getMemoryAccess();

    int value = std::any_cast<int>(stackAccessor->top());
    stackAccessor->pop();
    int memoryLocation = std::any_cast<int>(stackAccessor->top());
    stackAccessor->pop();

    memoryAccessor->writeInt(memoryLocation, value);
}