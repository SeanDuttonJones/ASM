#include "operation_factory.h"

void OperationFactory::registerOp(Opcode opcode, IOperationInitializer *initializer) {
    registry.insert({opcode, initializer});
}

Operation* OperationFactory::make(Opcode opcode, std::any operand) {
    return registry.at(opcode)->init(opcode, operand);
}