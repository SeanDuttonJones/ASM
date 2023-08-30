#include "initializers.h"
#include "instructions.hpp"

Operation* PushIInitializer::init(NewOpcode opcode, std::any operand) {
    return new PushIInstruction(opcode, operand);
}

Operation* AddIInitializer::init(NewOpcode opcode, std::any operand) {
    return new AddIInstruction(opcode, operand);
}

Operation* PStackInitializer::init(NewOpcode opcode, std::any operand) {
    return new PStackInstruction(opcode, operand);
}