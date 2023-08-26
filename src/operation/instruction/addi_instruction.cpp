#include "operation.hpp"
#include "instructions.hpp"

#include <iostream>
#include <any>

AddIInstruction::AddIInstruction(IContext *context) 
    : Operation(context, OperationType::INSTRUCTION, Opcode::AddI)
{}

void AddIInstruction::install() {
    // std::cout << "PushI: installing" << std::endl;
}

void AddIInstruction::execute() {
    // std::cout << "PushI: executing" << std::endl;
    IStackAccess *stackAccessor = context->getStackAccess();
    
    any operand1 = stackAccessor->top();
    stackAccessor->pop();
    any operand2 = stackAccessor->top();
    stackAccessor->pop();
    
    if(TypeTools::getType(std::type_index(operand1.type())) != Type::INT 
        || TypeTools::getType(std::type_index(operand2.type())) != Type::INT) {
        
        cerr << "Invalid operands for instruction AddI" << endl;
    }

    int a = std::any_cast<int>(operand1);
    int b = std::any_cast<int>(operand2);

    int sum = a + b;

    stackAccessor->push(sum);
}