#include "operation_factory.hpp"
#include "instructions.hpp"

Operation* OperationFactory::make(IContext *context, Opcode opcode, any value) {
    if(opcode == Opcode::PushI) return new PushIInstruction(context, value);
    if(opcode == Opcode::AddI) return new AddIInstruction(context);
    if(opcode == Opcode::PStack) return new PStackInstruction(context);
    // generate null instance
}