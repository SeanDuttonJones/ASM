#include "operation_factory.hpp"
#include "instructions.hpp"

Operation* OperationFactory::make(Asm *stackMachine, Opcode opcode, any value) {
    if(opcode == Opcode::PushI) return new PushIInstruction(stackMachine, value);

    // generate null instance
}