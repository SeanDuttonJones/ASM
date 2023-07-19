#ifndef ASM_CLASS_H
#define ASM_CLASS_H

#include <iostream>
#include <vector>
#include <variant>
#include "AsmOperation.hpp"

using namespace std;

class Asm {
    private:
        vector<ASMOperation> operations;
        vector<uint8_t> memory;
        // vector<Value<variant<bool, char, int, float>>> stack;
        int64_t pc;

    public:
        Asm();
        void run();
        void insertOperation(ASMOperation operation, int64_t location);
        void insertData(vector<uint8_t> data, int64_t location);
        void reset();
};

#endif