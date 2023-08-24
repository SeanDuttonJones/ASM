#ifndef OPERATION_FACTORY_H
#define OPERATION_FACTORY_H

#include "operation.hpp"
#include "Asm.hpp"
#include "Opcode.hpp"

class OperationFactory {
    public:
        static Operation* make(IContext *context, Opcode opcode, any value);
};

#endif