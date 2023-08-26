#include "operation.hpp"
#include "instructions.hpp"

#include <iostream>
#include <any>

PStackInstruction::PStackInstruction(IContext *context) 
    : Operation(context, OperationType::INSTRUCTION, Opcode::PStack)
{}

void PStackInstruction::install() {
    // std::cout << "PushI: installing" << std::endl;
}

void PStackInstruction::execute() {
    // std::cout << "PStack: executing" << std::endl;
    IStackAccess *stackAccessor = context->getStackAccess();
    
    uint64_t stackSize = stackAccessor->size();

    std::any elements[stackSize];
    for(uint64_t i = 0; i < stackSize; i++) {
        elements[i] = stackAccessor->top();
        stackAccessor->pop();
    }

    printf("[ ");
    for(uint64_t i = stackSize; i--;) {
        stackAccessor->push(elements[i]);
        printf("%s", anyToString(elements[i]).c_str());
        if(i > 0) {
            printf(" ");
        }
    }
    printf(" ]\n");
}

string PStackInstruction::anyToString(std::any value) {
    std::string valueStr = "";
    
    switch (TypeTools::getType(std::type_index(value.type()))) {
    case Type::BOOL:
        valueStr = std::to_string(std::any_cast<bool>(value));
        break;
    case Type::CHAR:
        valueStr = std::to_string(std::any_cast<char>(value));
        break;
    case Type::INT:
        valueStr = std::to_string(std::any_cast<int>(value));
        break;
    case Type::FLOAT:
        valueStr = std::to_string(std::any_cast<float>(value));
        break;
    case Type::DOUBLE:
        valueStr = std::to_string(std::any_cast<double>(value));
        break;
    case Type::STRING:
        valueStr = std::any_cast<std::string>(value);
        break;
    default:
        valueStr = "None";
        break;
    }

    return valueStr;
}