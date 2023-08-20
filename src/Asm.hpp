#ifndef ASM_CLASS_H
#define ASM_CLASS_H

#include <iostream>
#include <vector>
#include <array>
#include <variant>
#include "operation.hpp"

using namespace std;

// forward declaration since we have a circular dependency with operation.hpp
// TODO: fix circular dependency
class Operation;

class Asm {
    private:
        static const size_t MEMORY_SIZE = 65536;
        vector<Operation*> operations;
        array<unsigned char, MEMORY_SIZE> memory;
        size_t pc;

    public:
        Asm();
        ~Asm();
        void start();
        void insertOperation(Operation *operation, size_t location);
        void insertDataFloat(double data, size_t location);
        void insertDataInt(int data, size_t location);
        void insertDataChar(char data, size_t location);
        void reset();
};

#endif