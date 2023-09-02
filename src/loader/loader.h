#ifndef LOADER_CLASS_H
#define LOADER_CLASS_H

#include <iostream>
#include <filesystem>
#include <map>

#include "asm.h"
#include "operation.h"
#include "opcode_registry.h"
#include "operation_factory.h"

using namespace std;

class Loader {
    private:
        Asm *stackMachine;
        map<string, unsigned int> symbolTable;
        map<string, unsigned int> dataLabelTable;
        unsigned int iptr;
        unsigned int dptr;
        
        OpcodeRegistry *opcodeRegistry;
        OperationFactory *operationFactory;

        vector<string> readFile(std::filesystem::path input);
        
        Operation* parseLine(string line);
        void loadInstruction(Operation* pOperation);
        void loadLabel(Operation* pOperation);
        void loadDLabel(Operation* pOperation);
        void loadDirective(Operation* pOperation);
        void resolveSymbols();

        vector<string> tokenize(string line);
        any parseValue(string value);
    public:
        Loader(Asm *stackMachine, OpcodeRegistry *opcodeRegistry, OperationFactory *operationFactory);
        void load(std::filesystem::path input);
};

#endif