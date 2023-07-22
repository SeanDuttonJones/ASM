#ifndef ASM_LOADER_CLASS_H
#define ASM_LOADER_CLASS_H

#include <iostream>
#include <filesystem>
#include <any>
#include <map>
#include <vector>
#include "Asm.hpp"
#include "SymbolTable.hpp"
#include "AsmOperation.hpp"
#include "Opcode.hpp"

using namespace std;
namespace fs = std::filesystem;

class AsmLoader {
    private:
        Asm stackMachine;
        SymbolTable symbolTable;
        int64_t iptr;
        int64_t dptr;

        vector<string> readFile(fs::path asmFile);
        ASMOperation parseLine(string line);
        vector<string> tokenize(string line);
        any parseValue(string value);
    public:
        AsmLoader(Asm stackMachine);
        void load(fs::path asmFile);
};

#endif