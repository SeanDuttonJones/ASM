#ifndef LOADER_CLASS_H
#define LOADER_CLASS_H

#include <iostream>
#include <filesystem>
#include <map>

#include "Asm.hpp"
#include "SymbolTable.hpp"
#include "operation.hpp"

using namespace std;

class Loader {
    private:
        Asm *stackMachine;
        map<string, uint32_t> symbolTable;
        map<string, uint32_t> dataLabelTable;
        uint32_t iptr;
        uint32_t dptr;

        vector<string> readFile(std::filesystem::path input);
        
        Operation* parseLine(string line);
        void loadInstruction(Operation *pOperation);
        void loadLabel(Operation *pOperation);
        void loadDLabel(Operation *pOperation);
        void loadDirective(Operation *pOperation);
        void resolveSymbols();

        vector<string> tokenize(string line);
        any parseValue(string value);
    public:
        Loader(Asm *stackMachine);
        void load(std::filesystem::path input);
};

#endif