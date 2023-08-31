#include "operation.h"
#include "instructions.h"

#include <iostream>
#include <any>

NegIInstruction::NegIInstruction(Opcode opcode, std::any operand)
    : Operation(opcode, operand)
{}

void NegIInstruction::execute(IContext *context) {
    // std::cout << "PushI: executing" << std::endl;
    IStackAccess *stackAccessor = context->getStackAccess();
    
    std::any operand1 = stackAccessor->top();
    stackAccessor->pop();
    
    if(TypeTools::getType(std::type_index(operand1.type())) != Type::INT) {
        std::cerr << "Invalid operand for instruction NegI" << std::endl;
    }

    int a = std::any_cast<int>(operand1);

    int neg = -a;

    stackAccessor->push(neg);
}