#include "Asm.hpp"

Asm::Asm() {}

void Asm::start() {
    for(int i = 0; i < operations.size(); i++) {
        operations[i]->execute();
        pc++;
    }
}

void Asm::insertOperation(Operation *operation, int64_t location) {
    operations.insert(operations.begin() + location, operation);
}

void Asm::insertDataFloat(double data, size_t location) {
    
}

void Asm::insertDataInt(int data, size_t location) {

}

void Asm::insertDataChar(char data, size_t location) {

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