#include "operation_factory.h"
#include "instructions.hpp"

OperationFactory* OperationFactory::pInstance = NULL;

OperationFactory::OperationFactory() {}

OperationFactory* OperationFactory::getInstance() {
    if(pInstance = nullptr) {
        pInstance = new OperationFactory();
    }

    return pInstance;
}

void OperationFactory::registerOp(NewOpcode opcode, IOperationInitializer *initializer) {
    registry.insert({opcode, initializer});
}

Operation* OperationFactory::make(NewOpcode opcode, IContext *context, std::vector<std::any> operands) {
    if(auto search = registry.find(opcode); search != registry.end()) {
        return search->second->init(context, operands);
    }

    return nullptr;
}

// Operation* OperationFactory::make(IContext *context, Opcode opcode, any value) {
//     if(opcode == Opcode::PushI) return new PushIInstruction(context, value);
//     if(opcode == Opcode::AddI) return new AddIInstruction(context);
//     if(opcode == Opcode::PStack) return new PStackInstruction(context);
//     // generate null instance
// }