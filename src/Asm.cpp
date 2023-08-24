#include "Asm.hpp"

Asm::Asm(uint32_t memorySize) {
    this->pc = 0;

    this->stack = new std::stack<any>();
    
    this->memorySize = memorySize;
    this->memory = new vector<unsigned char>(memorySize);

    this->stackAccessor = new DefaultStackAccess(stack);
    this->memoryAccessor = new DefaultMemoryAccess(memory);
    this->context = new DefaultContext(stackAccessor, memoryAccessor);
}

Asm::Asm() {
    Asm(32);
}

void Asm::start() {    
    // print operation store
    printf("OPERATION STORE\n");
    for(uint64_t i = 0; i < operations.size(); i++) {
        printf("%lu\t: %s\n", i, operations[i]->toString().c_str());
    }
    printf("\n");
    
    // print memory
    printf("MEMORY\n");
    for(uint32_t i = 0; i < memorySize; i++) {
        printf("%u\t: 0x%02X\n", i, memory->at(i));
    }
    printf("\n");

    for(uint64_t i = 0; i < operations.size(); i++) {
        operations[i]->execute();
        pc++;
    }
}

void Asm::insertOperation(Operation *operation) {
    operations.push_back(operation);
}

void Asm::insertDataFloat(double data, uint32_t location) {
    unsigned char const *dp = reinterpret_cast<unsigned char const *>(&data);
    for(int i = 0; i != sizeof(double); i++) {
        memory->at(location + i) = dp[i];
    }
}

void Asm::insertDataInt(int data, uint32_t location) {
    unsigned char const *dp = reinterpret_cast<unsigned char const *>(&data);
    for(int i = 0; i != sizeof(int); i++) {
        memory->at(location + i) = dp[i];
    }
}

void Asm::insertDataChar(char data, uint32_t location) {
    unsigned char const *dp = reinterpret_cast<unsigned char const *>(&data);
    for(int i = 0; i != sizeof(char); i++) {
        memory->at(location + i) = dp[i];
    }
}

void Asm::insertDataAddress(uint32_t data, uint32_t location) {
    unsigned char const *dp = reinterpret_cast<unsigned char const *>(&data);
    for(int i = 0; i != sizeof(uint32_t); i++) {
        memory->at(location + i) = dp[i];
    }
}

vector<Operation*> Asm::getOperations() {
    return operations;
}

IContext* Asm::getContext() {
    return context;
}

void Asm::reset() {
    operations.clear();
    
    memory->clear();
    memory->reserve(memorySize);

    pc = 0;
}

Asm::~Asm() {
    if(operations.size() > 0) {
        for(int i = 0; i < operations.size(); i++) {
            delete operations[i];
        }
    }

    delete stack;
    delete memory;
    delete stackAccessor;
    delete memoryAccessor;
    delete context;
}