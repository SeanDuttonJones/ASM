#ifndef LOADER_CLASS_H
#define LOADER_CLASS_H

#include <iostream>
#include <filesystem>

#include "Asm.hpp"
#include "SymbolTable.hpp"
#include "operation.hpp"

using namespace std;

class Loader {
    private:
        Asm stackMachine;
        SymbolTable symbolTable;
        int64_t iptr;
        int64_t dptr;

        vector<string> readFile(std::filesystem::path input);
        
        std::tuple<Opcode, any> parseLine(string line);
        vector<string> tokenize(string line);
        any parseValue(string value);
    public:
        Loader(Asm stackMachine);
        void load(std::filesystem::path input);
};

#endif