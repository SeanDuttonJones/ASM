#ifndef OPERATION_ABS_H
#define OPERATION_ABS_H

#include <any>
#include <string>
#include "Asm.hpp"
#include "Opcode.hpp"
#include "Type.hpp"

// forward declaration since we have a circular dependency with Asm.hpp
// TODO: fix circular dependency
class Asm;

enum class OperationType {
    INSTRUCTION,
    LABEL,
    DLABEL,
    DIRECTIVE
};

class Operation {
    protected:
        Asm &stackMachine;
        OperationType operationType;
        Opcode opcode;
        std::any value;
        Type valueType;

    public:
        Operation(Asm &stackMachine, OperationType operationType, Opcode opcode);
        Operation(Asm &stackMachine, OperationType operationType, Opcode opcode, std::any value);
        virtual ~Operation();
        virtual void install();
        virtual void execute();
        virtual OperationType getOperationType();
        virtual Opcode getOpcode();
        virtual std::any getValue();
        virtual Type getValueType();
        virtual std::string toString();
};

#endif