#ifndef OPERATION_ABS_H
#define OPERATION_ABS_H

#include <any>
#include <string>
#include "Asm.hpp"
#include "Opcode.hpp"
#include "Type.hpp"

enum class OperationType {
    INSTRUCTION,
    DIRECTIVE
};

class Operation {
    private:
        Asm &stackMachine;
        OperationType operationType;
        Opcode opcode;
        any value;
        Type valueType;

    public:
        Operation(Asm &stackMachine, OperationType operationType, Opcode opcode);
        Operation(Asm &stackMachine, OperationType operationType, Opcode opcode, any value);
        virtual ~Operation();
        virtual void execute();
        virtual OperationType getOperationType();
        virtual Opcode getOpcode();
        virtual std::any getValue();
        virtual Type getValueType();
        virtual std::string toString();
};

#endif