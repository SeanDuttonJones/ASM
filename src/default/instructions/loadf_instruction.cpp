#include "instructions.h"

LoadFInstruction::LoadFInstruction(Opcode opcode, std::any operand) 
    : Operation(opcode, operand)
{}

void LoadFInstruction::execute(IContext *context) {
    IStackAccess *stackAccessor = context->getStackAccess();
    IMemoryAccess *memoryAccessor = context->getMemoryAccess();

    int memoryLocation = std::any_cast<int>(stackAccessor->top());
    stackAccessor->pop();

    double value = memoryAccessor->readDouble(memoryLocation);
    stackAccessor->push(value);
}