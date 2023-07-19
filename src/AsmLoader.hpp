#ifndef ASM_LOADER_CLASS_H
#define ASM_LOADER_CLASS_H

#include <iostream>
#include <filesystem>
#include <map>
#include <vector>
#include "Asm.hpp"
#include "AsmOperation.hpp"

using namespace std;
namespace fs = std::filesystem;

class AsmLoader {
    private:
        Asm stackMachine;
        int64_t iptr;
        int64_t dptr;
        map<string, int64_t> symbolTabel;

        ASMOperation parseLine(string line);
        vector<string> tokenize(string line);
    public:
        AsmLoader(Asm stackMachine);
        void load(fs::path asmFile);
};

#endif