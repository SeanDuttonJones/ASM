#include "operation_factory.h"
#include "instructions.hpp"

void OperationFactory::registerOp(NewOpcode opcode, IOperationInitializer *initializer) {
    registry.insert({opcode, initializer});
}

Operation* OperationFactory::make(NewOpcode opcode, std::any operand) {
    return registry.at(opcode)->init(opcode, operand);
}