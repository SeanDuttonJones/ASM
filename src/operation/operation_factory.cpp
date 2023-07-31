#include "operation_factory.hpp"

Operation OperationFactory::make(Asm &stackMachine, Opcode opcode, any value) {
    if(opcode == Opcode::PushI) return Operation(stackMachine, OperationType::INSTRUCTION, opcode, value);

    // generate null instance
}