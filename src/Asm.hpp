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
        static const uint32_t MEMORY_SIZE = 32;
        //static const uint32_t MEMORY_SIZE = 512000000; // default 512 megabytes of memory
        vector<Operation*> operations;
        array<unsigned char, MEMORY_SIZE> memory;
        uint64_t pc;

    public:
        Asm();
        ~Asm();
        void start();

        void insertOperation(Operation *operation);
        
        void insertDataFloat(double data, uint32_t location);
        void insertDataInt(int data, uint32_t location);
        void insertDataChar(char data, uint32_t location);
        void insertDataAddress(uint32_t data, uint32_t location);

        vector<Operation*> getOperations();

        void reset();
};

#endif