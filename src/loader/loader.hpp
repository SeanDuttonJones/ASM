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
        Asm stackMachine;
        SymbolTable symbolTable;
        map<string, size_t> dataLabelTable;
        size_t iptr;
        size_t dptr;

        vector<string> readFile(std::filesystem::path input);
        
        Operation* parseLine(string line);
        void loadInstruction(Operation *pOperation);
        void loadLabel(Operation *pOperation);
        void loadDLabel(Operation *pOperation);
        void loadDirective(Operation *pOperation);
        
        vector<string> tokenize(string line);
        any parseValue(string value);
    public:
        Loader(Asm stackMachine);
        void load(std::filesystem::path input);
};

#endif