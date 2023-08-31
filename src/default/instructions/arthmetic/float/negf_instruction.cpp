#include "operation.h"
#include "instructions.h"

#include <iostream>
#include <any>

NegFInstruction::NegFInstruction(Opcode opcode, std::any operand)
    : Operation(opcode, operand)
{}

void NegFInstruction::execute(IContext *context) {
    IStackAccess *stackAccessor = context->getStackAccess();
    
    std::any operand1 = stackAccessor->top();
    stackAccessor->pop();
    
    if(TypeTools::getType(std::type_index(operand1.type())) != Type::DOUBLE) {
        std::cerr << "Invalid operand for instruction NegF" << std::endl;
    }

    double a = std::any_cast<double>(operand1);

    double neg = -a;

    stackAccessor->push(neg);
}