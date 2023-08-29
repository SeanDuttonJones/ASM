#ifndef OPERATION_FACTORY_H
#define OPERATION_FACTORY_H

#include <vector>
#include <any>

#include "opcode.h"
#include "operation_initializer_interface.h"

class OperationFactory {
    private:
        static OperationFactory* pInstance;
        OperationFactory();

        std::map<NewOpcode, IOperationInitializer*> registry;

    public:
        OperationFactory(OperationFactory &other) = delete;
        void operator=(const OperationFactory &) = delete;

        static OperationFactory* getInstance();

        void registerOp(NewOpcode opcode, IOperationInitializer *initializer);
        Operation* make(NewOpcode opcode, IContext *context, std::vector<std::any> operands);
};

#endif