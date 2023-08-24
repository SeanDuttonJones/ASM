#include "operation_factory.hpp"
#include "instructions.hpp"

Operation* OperationFactory::make(IContext *context, Opcode opcode, any value) {
    if(opcode == Opcode::PushI) return new PushIInstruction(context, value);

    // generate null instance
}