#include "opcode.h"

Opcode::Opcode(OperationType type, std::string code, Type operandType) {
    this->type = type;
    this->code = code;
    this->operandType = operandType;
}

Opcode::Opcode() {
    this->type = OperationType::INSTRUCTION;
    this->code = "Nop";
    this->operandType = Type::NONE;
}

OperationType Opcode::getOperationType() {
    return type;
}

std::string Opcode::getCode() {
    return code;
}

Type Opcode::getOperandType() {
    return operandType;
}

bool Opcode::operator<(const Opcode &rhs) const {
    if(this->code < rhs.code) {
        return true;
    }

    return false;
}