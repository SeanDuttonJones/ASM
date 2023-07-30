#include "operation.hpp"

Operation::Operation(Asm *stackMachine, OperationType operationType, Opcode opcode) {
    this->stackMachine = stackMachine;
    this->operationType = operationType;
    this->opcode = opcode;
    this->value = 0;
    this->valueType = Type::NONE;
}

Operation::Operation(Asm *stackMachine, OperationType operationType, Opcode opcode, any value) {
    this->stackMachine = stackMachine;
    this->operationType = operationType;
    this->opcode = opcode;
    this->value = value;
    this->valueType = TypeTools::getType(std::type_index(value.type()));
}

Operation::~Operation() {};

void Operation::execute() {};

OperationType Operation::getOperationType() {
    return operationType;
}

Opcode Operation::getOpcode() {
    return opcode;
}

std::any Operation::getValue() {
    return value;
}

Type Operation::getValueType() {
    return valueType;
}

std::string Operation::toString() {
    std::string opcodeStr = OpcodeTools::toString(opcode);
    std::string valueStr = "";
    
    switch (valueType) {
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
        valueStr = std::any_cast<std::string>(value);
        break;
    default:
        valueStr = "None";
        break;
    }

    return "Opcode: " + opcodeStr + " | Value: " + valueStr + " | Type: " + TypeTools::toString(valueType);
}