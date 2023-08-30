#include "operation.h"

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
    
    Type operandType = opcode.getOperandType();
    if(operandType == Type::CHAR) {
        out += std::to_string(std::any_cast<char>(operand));

    } else if(operandType == Type::INT) {
        out += std::to_string(std::any_cast<int>(operand));

    } else if(operandType == Type::FLOAT) {
        out += std::to_string(std::any_cast<float>(operand));

    } else if(operandType == Type::DOUBLE) {
        out += std::to_string(std::any_cast<double>(operand));
    }

    return out;
}
// Operation::Operation(IContext *context, OperationType operationType, Opcode opcode) {
//     this->context = context;
//     this->operationType = operationType;
//     this->opcode = opcode;
//     this->value = 0;
//     this->valueType = Type::NONE;
// }

// Operation::Operation(IContext *context, OperationType operationType, Opcode opcode, any value) {
//     this->context = context;
//     this->operationType = operationType;
//     this->opcode = opcode;
//     this->value = value;
//     this->valueType = TypeTools::getType(std::type_index(value.type()));
// }

// Operation::~Operation() {};

// void Operation::install() {};

// void Operation::execute() {};

// OperationType Operation::getOperationType() {
//     return operationType;
// }

// Opcode Operation::getOpcode() {
//     return opcode;
// }

// Type Operation::getValueType() {
//     return valueType;
// }

// void Operation::setValueType(Type type) {
//     valueType = type;
// }

// std::any Operation::getValue() {
//     return value;
// }

// void Operation::setValue(std::any value) {
//     this->value = value;
// }

// std::string Operation::toString() {
//     std::string opcodeStr = OpcodeTools::toString(opcode);
//     std::string valueStr = "";
    
//     switch (valueType) {
//     case Type::BOOL:
//         valueStr = std::to_string(std::any_cast<bool>(value));
//         break;
//     case Type::CHAR:
//         valueStr = std::to_string(std::any_cast<char>(value));
//         break;
//     case Type::INT:
//         valueStr = std::to_string(std::any_cast<int>(value));
//         break;
//     case Type::FLOAT:
//         valueStr = std::to_string(std::any_cast<float>(value));
//         break;
//     case Type::DOUBLE:
//         valueStr = std::to_string(std::any_cast<double>(value));
//         break;
//     case Type::STRING:
//         valueStr = std::any_cast<std::string>(value);
//         break;
//     default:
//         valueStr = "None";
//         break;
//     }

//     return "Opcode: " + opcodeStr + " | Value: " + valueStr + " | Type: " + TypeTools::toString(valueType);
// }