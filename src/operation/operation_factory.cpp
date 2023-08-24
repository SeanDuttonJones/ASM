#include "operation_factory.hpp"
#include "instructions.hpp"

Operation* OperationFactory::make(std::stack<std::any> *stack, Opcode opcode, any value) {
    if(opcode == Opcode::PushI) return new PushIInstruction(stack, value);

    // generate null instance
}