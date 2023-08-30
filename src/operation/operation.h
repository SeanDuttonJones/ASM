#ifndef OPERATION_ABS_H
#define OPERATION_ABS_H

#include <vector>
#include <any>
#include <string>

#include "context_interface.hpp"
#include "opcode.h"

// class Operation {
//     protected:
//         IContext *context;
        
//         OperationType operationType;
//         Opcode opcode;
        
//         std::any value;
//         Type valueType;

//     public:
//         Operation(IContext *context, OperationType operationType, Opcode opcode);
//         Operation(IContext *context, OperationType operationType, Opcode opcode, std::any value);
//         virtual ~Operation();
        
//         virtual void install();
//         virtual void execute();
        
//         virtual OperationType getOperationType();
//         virtual Opcode getOpcode();
        
//         virtual Type getValueType();
//         virtual void setValueType(Type type);

//         virtual std::any getValue();
//         virtual void setValue(std::any value);

//         virtual std::string toString();
// };
class Operation {
    protected:
        Opcode opcode;
        std::any operand;

    public:
        Operation(Opcode opcode, std::any operand);

        virtual void execute(IContext *context) = 0;

        virtual Opcode getOpcode();
        virtual std::any getOperand();
        virtual std::string toString();
};

#endif