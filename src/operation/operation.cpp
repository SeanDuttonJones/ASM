#include "operation.h"

#include <iostream>

Operation::Operation(Opcode opcode, std::any operand) {
    this->opcode = opcode;
    this->operand = operand;
}

Opcode Operation::getOpcode() {
    return opcode;
}

std::any Operation::getOperand() {
    return operand;
}

std::string Operation::toString() {
    std::string out = "";
    
    out += opcode.getCode() + " ";
    
    if(opcode.getOperandType() == Type::NONE) {
        return out;
    }
    
    Type operandType = TypeTools::getType(std::type_index(operand.type()));
    if(operandType == Type::CHAR) {
        out += std::to_string(std::any_cast<char>(operand));

    } else if(operandType == Type::INT) {
        out += std::to_string(std::any_cast<int>(operand));

    } else if(operandType == Type::UNSIGNED_INT) {
        out += std::to_string(std::any_cast<unsigned int>(operand));

    } else if(operandType == Type::FLOAT) {
        out += std::to_string(std::any_cast<float>(operand));

    } else if(operandType == Type::DOUBLE) {
        out += std::to_string(std::any_cast<double>(operand));

    } else if(operandType == Type::STRING) {
        out += std::any_cast<std::string>(operand);
    }

    return out;
}