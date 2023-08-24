#ifndef OPERATION_FACTORY_H
#define OPERATION_FACTORY_H

#include "operation.hpp"
#include "Asm.hpp"
#include "Opcode.hpp"

class OperationFactory {
    public:
        static Operation* make(std::stack<std::any> *stack, Opcode opcode, any value);
};

#endif