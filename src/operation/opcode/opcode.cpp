#include "opcode.h"

NewOpcode::NewOpcode(uint32_t numCode, std::string textCode, std::vector<Type> operandTypes, OperationType type) {
    this->numCode = numCode;
    this->textCode = textCode;
    this->operandTypes = operandTypes;
    this->numOperands = operandTypes.size();
    this->type = type;
}

uint32_t NewOpcode::getNumberCode() {
    return numCode;
}

std::string NewOpcode::getTextCode() {
    return textCode;
}

std::vector<Type> NewOpcode::getOperandTypes() {
    return operandTypes;
}

uint32_t NewOpcode::getNumOperands() {
    return numOperands;
}

OperationType NewOpcode::getOperationType() {
    return type;
}

bool NewOpcode::operator<(const NewOpcode &rhs) const {
    if(this->numCode < rhs.numCode) {
        return true;
    }

    return false;
}