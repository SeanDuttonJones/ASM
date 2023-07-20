#include "AsmLoader.hpp"
#include <fstream>
#include <string>

AsmLoader::AsmLoader(Asm stackMachine) {
    stackMachine = stackMachine;
    iptr = 0;
    dptr = 0;
}

void AsmLoader::load(fs::path asmFile) {
    ifstream source;
    source.open(asmFile);
    if(source.is_open()) {
        string line;
        while(getline(source, line)) {
            ASMOperation operation = parseLine(line);
            cout << operation.toString() << endl;
        }
    }
}

ASMOperation AsmLoader::parseLine(string line) {
    vector<string> v = tokenize(line);
    if(v.size() > 2) {
        ASMOperation operation(Opcode::Error);
        return operation;
    }

    Opcode op = OpcodeTools::getOpcode(v.at(0));
   
    if(v.size() == 1) {
        ASMOperation operation(op);
        return operation;
    }

    any value = stoi(v.at(1));
    ASMOperation operation(op, value);
    return operation;
}

vector<string> AsmLoader::tokenize(string line) {
    stringstream ss(line);
    vector<string> v;

    while(getline(ss, line, ' ')) {
        v.push_back(line);
    }

    return v;
}