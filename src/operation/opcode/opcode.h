#ifndef OPCODE_CLASS
#define OPCODE_CLASS

#include <cstdint>
#include <string>
#include <vector>

#include "Type.hpp"
#include "operation.hpp"

class NewOpcode {
    private:
        uint32_t numCode;
        std::string textCode;
        std::vector<Type> operandTypes;
        uint32_t numOperands;
        OperationType type;

    public:
        NewOpcode(uint32_t numCode, std::string textCode, std::vector<Type> operandTypes, OperationType type);
        
        uint32_t getNumberCode();
        std::string getTextCode();
        std::vector<Type> getOperandTypes();
        uint32_t getNumOperands();
        OperationType getOperationType();
};

#endif