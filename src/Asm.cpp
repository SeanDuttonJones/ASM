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

void Asm::insertData(vector<uint8_t> data, int64_t location) {

}

void Asm::reset() {
    operations.clear();
    memory.clear();
    pc = 0;
}

Asm::~Asm() {
    if(operations.size() > 0) {
        for(int i = 0; i < operations.size(); i++) {
            delete operations[i];
        }
    }
}