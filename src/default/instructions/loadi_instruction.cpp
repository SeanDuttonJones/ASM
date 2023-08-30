#include "instructions.hpp"

LoadIInstruction::LoadIInstruction(Opcode opcode, std::any operand) 
    : Operation(opcode, operand)
{}

void LoadIInstruction::execute(IContext *context) {
    IStackAccess *stackAccessor = context->getStackAccess();
    IMemoryAccess *memoryAccessor = context->getMemoryAccess();

    int memoryLocation = std::any_cast<int>(stackAccessor->top());
    stackAccessor->pop();

    int value = memoryAccessor->readInt(memoryLocation);
    stackAccessor->push(value);
}