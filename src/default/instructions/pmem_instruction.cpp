#include "instructions.hpp"

PMemInstruction::PMemInstruction(Opcode opcode, std::any operand)
    : Operation(opcode, operand)
{}

void PMemInstruction::execute(IContext *context) {
    IMemoryAccess *memoryAccessor = context->getMemoryAccess();

    for(uint32_t i = 0; i < memoryAccessor->size(); i++) {
        printf("%u\t: 0x%02X\n", i, memoryAccessor->readChar(i));
    }
}