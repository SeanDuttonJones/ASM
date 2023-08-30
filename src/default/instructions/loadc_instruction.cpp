#include "instructions.h"

LoadCInstruction::LoadCInstruction(Opcode opcode, std::any operand) 
    : Operation(opcode, operand)
{}

void LoadCInstruction::execute(IContext *context) {
    IStackAccess *stackAccessor = context->getStackAccess();
    IMemoryAccess *memoryAccessor = context->getMemoryAccess();

    int memoryLocation = std::any_cast<int>(stackAccessor->top());
    stackAccessor->pop();

    char value = memoryAccessor->readChar(memoryLocation);
    stackAccessor->push(value);
}