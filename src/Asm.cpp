#include "Asm.hpp"

Asm::Asm() {}

void Asm::run() {

}

void Asm::insertOperation(Operation *operation, int64_t location) {

}

void Asm::insertData(vector<uint8_t> data, int64_t location) {

}

void Asm::reset() {
    
}

Asm::~Asm() {
    if(operations.size() > 0) {
        for(int i = 0; i < operations.size(); i++) {
            delete operations[i];
        }
    }
}