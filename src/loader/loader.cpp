#include "loader.h"

#include <fstream>
#include <any>

#include "opcode.h"
#include "opcode_registry.h"
#include "operation_factory.h"

Loader::Loader(Asm *stackMachine, OpcodeRegistry *opcodeRegistry, OperationFactory *operationFactory) {
    this->stackMachine = stackMachine;
    this->iptr = 0;
    this->dptr = 0;

    this->opcodeRegistry = opcodeRegistry;
    this->operationFactory = operationFactory;
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
        Operation *pOperation = parseLine(line);

        OperationType operationType = pOperation->getOpcode().getOperationType();
        if(operationType == OperationType::INSTRUCTION) {
            loadInstruction(pOperation);

        } else if(operationType == OperationType::LABEL) {
            loadLabel(pOperation);

        } else if(operationType == OperationType::DLABEL) {
            loadDLabel(pOperation);

        } else if(operationType == OperationType::DIRECTIVE) {
            loadDirective(pOperation);
        }

        resolveSymbols();
        // cout << pOperation->toString() << endl;
    }
}

void Loader::loadInstruction(Operation *pOperation) {
    // cout << "INSTRUCTION" << endl;
    stackMachine->insertOperation(pOperation);
    iptr++;
}

void Loader::loadLabel(Operation *pOperation) {
    // cout << "LABEL" << endl;
    string label = any_cast<string>(pOperation->getOperand());
    symbolTable.insert({label, iptr});
}

void Loader::loadDLabel(Operation *pOperation) {
    // cout << "DLABEL" << endl;
    string label = any_cast<string>(pOperation->getOperand());
    symbolTable.insert({label, dptr});
}

void Loader::loadDirective(Operation *pOperation) {
    IMemoryAccess *memoryAccessor = stackMachine->getContext()->getMemoryAccess();
    // cout << "DIRECTIVE" << endl;
    Type operandType = pOperation->getOpcode().getOperandType();
    if(operandType == Type::CHAR) {
        char data = any_cast<char>(pOperation->getOperand());
        memoryAccessor->writeChar(dptr, data);
        dptr += sizeof(char);

    } else if(operandType == Type::INT) {
        int data = any_cast<int>(pOperation->getOperand());
        memoryAccessor->writeInt(dptr, data);
        dptr += sizeof(int);

    } else if(operandType == Type::DOUBLE) {
        double data = any_cast<double>(pOperation->getOperand());
        memoryAccessor->writeDouble(dptr, data);
        dptr += sizeof(double);

    } else if(operandType == Type::STRING) {
        string dataLabel = any_cast<string>(pOperation->getOperand());
        dataLabelTable.insert({dataLabel, dptr});
        dptr += sizeof(uint32_t);

    } else {
        cerr << "Invalid data type for OperationType Directive" << endl;
    }
}

void Loader::resolveSymbols() {
    // resolve in instruction store first
    for(Operation *pOperation : stackMachine->getOperations()) {
        Opcode opcode = pOperation->getOpcode();
        OperationType operationType = opcode.getOperationType();
        if(operationType == OperationType::LABEL || operationType == OperationType::DLABEL) {
            string oldValue = any_cast<string>(pOperation->getOperand());
            delete pOperation;
            pOperation = operationFactory->make(opcode, symbolTable.at(oldValue));
        }
    }

    // resolve in memory second
    IMemoryAccess *memoryAccessor = stackMachine->getContext()->getMemoryAccess();
    for(auto const& [symbol, location] : dataLabelTable) {
        uint32_t address = symbolTable.at(symbol);
        memoryAccessor->writeAddress(location, address);
    }
}

Operation* Loader::parseLine(string line) {
    vector<string> tokens = tokenize(line);
    if(tokens.size() == 0 || tokens.size() > 2) {
        cerr << "Invalid operation" << endl;
        exit(1);
    }

    Opcode opcode = opcodeRegistry->retrieveOp(tokens[0]);
    any operand = 0;
    if(tokens.size() == 2) {
        operand = parseValue(tokens[1]);
    }

    Operation *pOperation = operationFactory->make(opcode, operand);
    return pOperation;
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
            double fValue = std::stod(value, &pos);
            
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