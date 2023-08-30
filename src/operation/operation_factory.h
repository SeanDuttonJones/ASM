#ifndef OPERATION_FACTORY_H
#define OPERATION_FACTORY_H

#include <any>
#include <map>

#include "opcode.h"
#include "operation_initializer_interface.h"

class OperationFactory {
    private:
        std::map<Opcode, IOperationInitializer*> registry;

    public:
        void registerOp(Opcode opcode, IOperationInitializer *initializer);
        Operation* make(Opcode opcode, std::any operand);
};

#endif