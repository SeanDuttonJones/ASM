#include "AsmOperation.hpp"

ASMOperation::ASMOperation(Opcode opcode) {
    this->opcode = opcode;
    this->value = 0;
    this->type = Type::NONE;
}

ASMOperation::ASMOperation(Opcode opcode, any value) {
    this->opcode = opcode;
    this->value = value;
    this->type = TypeTools::getType(type_index(value.type()));
}

Opcode ASMOperation::getOpcode() {
    return opcode;
}

any ASMOperation::getValue() {
    return value;
}

Type ASMOperation::getType() {
    return type;
}