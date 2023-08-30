#include "initializers.h"
#include "instructions.h"

Operation* PushIInitializer::init(Opcode opcode, std::any operand) {
    return new PushIInstruction(opcode, operand);
}

Operation* PushFInitializer::init(Opcode opcode, std::any operand) {
    return new PushFInstruction(opcode, operand);
}

Operation* AddIInitializer::init(Opcode opcode, std::any operand) {
    return new AddIInstruction(opcode, operand);
}

Operation* PStackInitializer::init(Opcode opcode, std::any operand) {
    return new PStackInstruction(opcode, operand);
}

Operation* PMemInitializer::init(Opcode opcode, std::any operand) {
    return new PMemInstruction(opcode, operand);
}

Operation* StoreCInitializer::init(Opcode opcode, std::any operand) {
    return new StoreCInstruction(opcode, operand);
}

Operation* StoreIInitializer::init(Opcode opcode, std::any operand) {
    return new StoreIInstruction(opcode, operand);
}

Operation* StoreFInitializer::init(Opcode opcode, std::any operand) {
    return new StoreFInstruction(opcode, operand);
}

Operation* LoadCInitializer::init(Opcode opcode, std::any operand) {
    return new LoadCInstruction(opcode, operand);
}

Operation* LoadIInitializer::init(Opcode opcode, std::any operand) {
    return new LoadIInstruction(opcode, operand);
}

Operation* LoadFInitializer::init(Opcode opcode, std::any operand) {
    return new LoadFInstruction(opcode, operand);
}