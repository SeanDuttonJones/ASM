#include "initializers.h"
#include "instructions.hpp"

Operation* PushIInitializer::init(Opcode opcode, std::any operand) {
    return new PushIInstruction(opcode, operand);
}

Operation* AddIInitializer::init(Opcode opcode, std::any operand) {
    return new AddIInstruction(opcode, operand);
}

Operation* PStackInitializer::init(Opcode opcode, std::any operand) {
    return new PStackInstruction(opcode, operand);
}