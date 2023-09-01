#include "asm.h"

Asm::Asm(uint32_t memorySize) 
    : stackAccessor(&stack), memoryAccessor(&memory), pcAccessor(&pc), 
        context(&stackAccessor, &memoryAccessor, &pcAccessor)
{
    this->pc = 0;
    
    this->memorySize = memorySize;
    this->memory.resize(memorySize, 0);
}

Asm::Asm() : Asm(32) {}

void Asm::start(bool debug) {
    if(debug) {
        // print operation store
        printf("OPERATION STORE\n");
        for(uint64_t i = 0; i < operations.size(); i++) {
            printf("%lu\t: %s\n", i, operations[i]->toString().c_str());
        }
        printf("\n");
        
        // print memory
        printf("MEMORY\n");
        for(uint32_t i = 0; i < memorySize; i++) {
            printf("%u\t: 0x%02X\n", i, memory.at(i));
        }
        printf("\n");

        printf("OUTPUT\n");
    }

    for(uint64_t i = 0; i < operations.size(); i++) {
        pc++;
        operations[i]->execute(&context);
    }
}

void Asm::reset() {
    operations.clear();
    
    memory.clear();
    memory.resize(memorySize, 0);

    pc = 0;
}

void Asm::insertOperation(Operation *operation) {
    operations.push_back(operation);
}

vector<Operation*> Asm::getOperations() {
    return operations;
}

IContext* Asm::getContext() {
    return &context;
}

Asm::~Asm() {
    if(operations.size() > 0) {
        for(int i = 0; i < operations.size(); i++) {
            delete operations[i];
        }
    }
}