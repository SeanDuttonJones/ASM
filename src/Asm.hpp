#ifndef ASM_CLASS_H
#define ASM_CLASS_H

#include <iostream>
#include <vector>
#include <stack>
#include <array>
#include <any>

#include "operation.hpp"

#include "default_context.hpp"
#include "default_stack_access.hpp"
#include "default_memory_access.hpp"

using namespace std;

// forward declaration since we have a circular dependency with operation.hpp
// TODO: fix circular dependency
class Operation;

class Asm {
    private:
        vector<Operation*> operations;
        uint64_t pc;

        std::stack<std::any> *stack;

        uint32_t memorySize;
        vector<unsigned char> *memory;

        DefaultStackAccess *stackAccessor;
        DefaultMemoryAccess *memoryAccessor;
        DefaultContext *context;

    public:
        Asm();
        Asm(uint32_t memorySize);
        ~Asm();
        void start();

        void insertOperation(Operation *operation);

        void insertDataFloat(double data, uint32_t location);
        void insertDataInt(int data, uint32_t location);
        void insertDataChar(char data, uint32_t location);
        void insertDataAddress(uint32_t data, uint32_t location);

        vector<Operation*> getOperations();
        IContext* getContext();

        void reset();
};

#endif