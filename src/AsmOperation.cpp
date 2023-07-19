#include "AsmOperation.hpp"

ASMOperation::ASMOperation(Opcode opcode) {
    this->opcode = opcode;
}

ASMOperation::ASMOperation(Opcode opcode, any value) {
    this->opcode = opcode;
    this->value = value;
}

Opcode ASMOperation::getOpcode() {
    return opcode;
}

any ASMOperation::getValue() {
    return value;
}