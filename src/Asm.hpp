#ifndef ASM_CLASS_H
#define ASM_CLASS_H

#include <iostream>
#include <vector>
#include <variant>
#include "operation.hpp"

using namespace std;

// forward declaration since we have a circular dependency with operation.hpp
// TODO: fix circular dependency
class Operation;

class Asm {
    private:
        vector<Operation*> operations;
        vector<uint8_t> memory;
        int64_t pc;

    public:
        Asm();
        ~Asm();
        void start();
        void insertOperation(Operation *operation, int64_t location);
        void insertData(vector<uint8_t> data, int64_t location);
        void reset();
};

#endif