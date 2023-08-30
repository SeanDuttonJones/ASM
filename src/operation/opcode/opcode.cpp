#include "opcode.h"

NewOpcode::NewOpcode(OperationType type, std::string code, Type operandType) {
    this->type = type;
    this->code = code;
    this->operandType = operandType;
}

NewOpcode::NewOpcode() {
    this->type = OperationType::INSTRUCTION;
    this->code = "Nop";
    this->operandType = Type::NONE;
}

OperationType NewOpcode::getOperationType() {
    return type;
}

std::string NewOpcode::getCode() {
    return code;
}

Type NewOpcode::getOperandType() {
    return operandType;
}

bool NewOpcode::operator<(const NewOpcode &rhs) const {
    if(this->code < rhs.code) {
        return true;
    }

    return false;
}