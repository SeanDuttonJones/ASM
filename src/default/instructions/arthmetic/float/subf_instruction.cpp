#include "operation.h"
#include "instructions.h"

#include <iostream>
#include <any>

SubFInstruction::SubFInstruction(Opcode opcode, std::any operand)
    : Operation(opcode, operand)
{}

void SubFInstruction::execute(IContext *context) {
    IStackAccess *stackAccessor = context->getStackAccess();
    
    std::any operand1 = stackAccessor->top();
    stackAccessor->pop();
    std::any operand2 = stackAccessor->top();
    stackAccessor->pop();
    
    if(TypeTools::getType(std::type_index(operand1.type())) != Type::DOUBLE 
        || TypeTools::getType(std::type_index(operand2.type())) != Type::DOUBLE) {
        
        std::cerr << "Invalid operands for instruction SubF" << std::endl;
    }

    double a = std::any_cast<double>(operand2);
    double b = std::any_cast<double>(operand1);

    double dif = a - b;

    stackAccessor->push(dif);
}