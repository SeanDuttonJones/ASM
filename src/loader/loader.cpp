#include "loader.hpp"

#include <fstream>
#include "operation_factory.hpp"

Loader::Loader(Asm stackMachine)
{
    this->stackMachine = stackMachine;
    this->iptr = 0;
    this->dptr = 0;
}

vector<string> Loader::readFile(std::filesystem::path input) {
    vector<string> lines;
    
    ifstream source;
    source.open(input);
    if(source.is_open()) {
        string line;
        while(getline(source, line)) {
            lines.push_back(line);
        }
    }

    return lines;
}

void Loader::load(std::filesystem::path input) {
    vector<string> lines = readFile(input);

    string line;
    for(int i = 0; i < lines.size(); i++) {
        line = lines[i];

        Operation &operation = parseOperation(line);
        stackMachine.insertOperation(operation, iptr);
        
        iptr++;

        // Not calling derived class because of code slicing. Must fix with references.
        operation.install();

        std::cout << operation.toString() << std::endl;
    }
}

Operation& Loader::parseOperation(string line) {
    vector<string> tokens = tokenize(line);
    if(tokens.size() == 0 || tokens.size() > 2) {
        cerr << "Invalid operation" << endl;
        exit(1);
    }

    Opcode opcode = OpcodeTools::getOpcode(tokens[0]);
    any value = 0;
    if(tokens.size() == 2) {
        value = parseValue(tokens[1]);
    }

    Operation operation = OperationFactory::make(stackMachine, opcode, value);
    return operation;
}

vector<string> Loader::tokenize(string line) {
    vector<string> v;
    
    string acc = "";
    char currentChar = line[0];
    for(int i = 0; i <= line.size(); i++) {
        currentChar = line[i];
        if(std::isspace(currentChar) || currentChar == '\0') {
            if(acc.size() > 0) {
                v.push_back(acc);
            }

            if(currentChar == '\0') {
                break;
            }

            acc = "";
            continue;
        }

        acc += currentChar;
    }

    return v;
}

any Loader::parseValue(string value) {
    try {
        size_t pos = 0;
        int iValue = std::stoi(value, &pos);
        
        if(pos < value.size() && value[pos] == '.') {
            float fValue = std::stof(value, &pos);
            
            if(pos < value.size()) {
                return value;
            }

            return fValue;
        }

        return iValue;
    } catch(const std::invalid_argument &ex) {
        return value;
    } catch(const std::out_of_range &ex) {
        return value;
    }
}