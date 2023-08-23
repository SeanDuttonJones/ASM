#include "Asm.hpp"

Asm::Asm() {}

void Asm::start() {
    cout << "STARTING STACK MACHINE..." << endl;
    
    // print operation store
    printf("OPERATION STORE\n");
    for(uint64_t i = 0; i < operations.size(); i++) {
        printf("%lu\t:%s\n", i, operations[i]->toString().c_str());
    }
    printf("\n");
    
    // print memory
    printf("MEMORY\n");
    for(uint32_t i = 0; i < MEMORY_SIZE; i++) {
        printf("%u\t: 0x%02X\n", i, memory[i]);
    }
    printf("\n");

    for(uint64_t i = 0; i < operations.size(); i++) {
        operations[i]->execute();
        pc++;
    }
}

void Asm::insertOperation(Operation *operation) {
    operations.push_back(operation);
    cout << "INSERT OPERATION: SIZE - " << operations.size() << endl;
}

void Asm::insertDataFloat(double data, uint32_t location) {
    unsigned char const *dp = reinterpret_cast<unsigned char const *>(&data);
    for(int i = 0; i != sizeof(double); i++) {
        memory[location + i] = dp[i];
    }
}

void Asm::insertDataInt(int data, uint32_t location) {
    unsigned char const *dp = reinterpret_cast<unsigned char const *>(&data);
    for(int i = 0; i != sizeof(int); i++) {
        memory[location + i] = dp[i];
    }
}

void Asm::insertDataChar(char data, uint32_t location) {
    unsigned char const *dp = reinterpret_cast<unsigned char const *>(&data);
    for(int i = 0; i != sizeof(char); i++) {
        memory[location + i] = dp[i];
    }
}

void Asm::insertDataAddress(uint32_t data, uint32_t location) {
    unsigned char const *dp = reinterpret_cast<unsigned char const *>(&data);
    for(int i = 0; i != sizeof(uint32_t); i++) {
        memory[location + i] = dp[i];
    }
}

vector<Operation*> Asm::getOperations() {
    return operations;
}

void Asm::reset() {
    operations.clear();
    memory.fill(0);
    pc = 0;
}

Asm::~Asm() {
    if(operations.size() > 0) {
        for(int i = 0; i < operations.size(); i++) {
            delete operations[i];
        }
    }
}