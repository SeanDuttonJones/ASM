#ifndef OPERATION_FACTORY_H
#define OPERATION_FACTORY_H

#include <any>
#include <map>

#include "opcode.h"
#include "operation_initializer_interface.h"

class OperationFactory {
    private:
        std::map<NewOpcode, IOperationInitializer*> registry;

    public:
        void registerOp(NewOpcode opcode, IOperationInitializer *initializer);
        Operation* make(NewOpcode opcode, std::any operand);
};

#endif