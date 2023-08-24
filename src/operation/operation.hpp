#ifndef OPERATION_ABS_H
#define OPERATION_ABS_H

#include <any>
#include <string>
#include <stack>

#include "Asm.hpp"
#include "Opcode.hpp"
#include "Type.hpp"

// forward declaration since we have a circular dependency with Asm.hpp
// TODO: fix circular dependency
// class Asm;

enum class OperationType {
    INSTRUCTION,
    LABEL,
    DLABEL,
    DIRECTIVE
};

class Operation {
    protected:
        std::stack<std::any> *stack;
        
        OperationType operationType;
        Opcode opcode;
        
        std::any value;
        Type valueType;

    public:
        Operation(std::stack<std::any> *stack, OperationType operationType, Opcode opcode);
        Operation(std::stack<std::any> *stack, OperationType operationType, Opcode opcode, std::any value);
        virtual ~Operation();
        
        virtual void install();
        virtual void execute();
        
        virtual OperationType getOperationType();
        virtual Opcode getOpcode();
        
        virtual Type getValueType();
        virtual void setValueType(Type type);

        virtual std::any getValue();
        virtual void setValue(std::any value);

        virtual std::string toString();
};

#endif