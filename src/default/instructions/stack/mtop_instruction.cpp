#include "instructions.h"

#include <iostream>

MtopInstruction::MtopInstruction(Opcode opcode, std::any operand) 
    : Operation(opcode, operand)
{}

void MtopInstruction::execute(IContext *context) {
    IStackAccess *stackAccessor = context->getStackAccess();
    IMemoryAccess *memoryAccessor = context->getMemoryAccess();
    
    int size = memoryAccessor->size();
    stackAccessor->push(size);
}