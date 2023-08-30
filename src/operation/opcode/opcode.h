#ifndef OPCODE_CLASS
#define OPCODE_CLASS

#include <cstdint>
#include <string>
#include <vector>

#include "Type.hpp"

enum class OperationType {
    INSTRUCTION,
    LABEL,
    DLABEL,
    DIRECTIVE
};

class NewOpcode {
    private:
        OperationType type;
        std::string code;
        Type operandType;

    public:
        NewOpcode(OperationType type, std::string code, Type operandType);
        NewOpcode();
        
        OperationType getOperationType();
        std::string getCode();
        Type getOperandType();

        bool operator<(const NewOpcode &rhs) const;
};

#endif