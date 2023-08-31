#include "instructions.h"

PMemInstruction::PMemInstruction(Opcode opcode, std::any operand)
    : Operation(opcode, operand)
{}

void PMemInstruction::execute(IContext *context) {
    IMemoryAccess *memoryAccessor = context->getMemoryAccess();

    unsigned char data = 0;
    unsigned char *dp = reinterpret_cast<unsigned char *>(&data);
    
    for(uint32_t i = 0; i < memoryAccessor->size(); i++) {
        memoryAccessor->read(i, sizeof(unsigned char), dp);
        printf("%u\t: 0x%02X\n", i, data);
    }
}