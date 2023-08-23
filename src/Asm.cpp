#include "Asm.hpp"

Asm::Asm() {}

void Asm::start() {
    cout << "STARTING STACK MACHINE" << endl;
    
    // print operation store
    cout << "OPERATION STORE SIZE: " << operations.size() << endl;
    for(uint64_t i = 0; i < operations.size(); i++) {
        cout << i << " : " << operations[i]->toString() << endl;
    }
    
    // print memory

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