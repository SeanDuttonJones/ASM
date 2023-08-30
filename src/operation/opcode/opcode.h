#ifndef OPCODE_CLASS
#define OPCODE_CLASS

#include <cstdint>
#include <string>
#include <vector>

#include "type.h"

enum class OperationType {
    INSTRUCTION,
    LABEL,
    DLABEL,
    DIRECTIVE
};

class Opcode {
    private:
        OperationType type;
        std::string code;
        Type operandType;

    public:
        Opcode(OperationType type, std::string code, Type operandType);
        Opcode();
        
        OperationType getOperationType();
        std::string getCode();
        Type getOperandType();

        bool operator<(const Opcode &rhs) const;
};

#endif