#include "AsmOperation.hpp"

ASMOperation::ASMOperation(Opcode opcode) {
    this->opcode = opcode;
    this->value = 0;
    this->type = Type::NONE;
}

ASMOperation::ASMOperation(Opcode opcode, std::any value) {
    this->opcode = opcode;
    this->value = value;
    this->type = TypeTools::getType(std::type_index(value.type()));
}

Opcode ASMOperation::getOpcode() {
    return opcode;
}

std::any ASMOperation::getValue() {
    return value;
}

Type ASMOperation::getType() {
    return type;
}

std::string ASMOperation::toString() {
    std::string opcodeStr = OpcodeTools::toString(opcode);
    std::string valueStr = "";
    
    switch (type) {
    case Type::BOOLEAN:
        valueStr = std::to_string(std::any_cast<bool>(value));
        break;
    case Type::CHARACTER:
        valueStr = std::to_string(std::any_cast<char>(value));
        break;
    case Type::INTEGER:
        valueStr = std::to_string(std::any_cast<int>(value));
        break;
    case Type::FLOAT:
        valueStr = std::to_string(std::any_cast<float>(value));
        break;
    case Type::STRING:
        valueStr = std::any_cast<char*>(value);
        break;
    default:
        break;
    }

    return "Opcode: " + opcodeStr + " | Value: " + valueStr;
}