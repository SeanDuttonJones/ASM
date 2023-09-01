#ifndef ASM_CLASS_H
#define ASM_CLASS_H

#include <iostream>
#include <vector>
#include <stack>
#include <array>
#include <any>

#include "operation.h"

#include "default_context.hpp"
#include "default_stack_access.hpp"
#include "default_memory_access.hpp"

using namespace std;

class Operation;

class Asm {
    private:
        vector<Operation*> operations;
        uint64_t pc;

        std::stack<std::any> stack;

        uint32_t memorySize;
        vector<unsigned char> memory;

        DefaultStackAccess stackAccessor;
        DefaultMemoryAccess memoryAccessor;
        DefaultPCAccess pcAccessor;
        DefaultContext context;

    public:
        Asm();
        Asm(uint32_t memorySize);
        ~Asm();

        void start(bool debug = false);
        void reset();

        void insertOperation(Operation *operation);
        vector<Operation*> getOperations();
        
        IContext* getContext();
};

#endif