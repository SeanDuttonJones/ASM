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
        static const uint32_t MEMORY_SIZE = 65536;
        vector<Operation*> operations;
        array<unsigned char, MEMORY_SIZE> memory;
        uint32_t pc;

    public:
        Asm();
        ~Asm();
        void start();
        void insertOperation(Operation *operation, uint32_t location);
        void insertDataFloat(double data, uint32_t location);
        void insertDataInt(int data, uint32_t location);
        void insertDataChar(char data, uint32_t location);
        void insertDataAddress(uint32_t data, uint32_t location);
        void reset();
};

#endif