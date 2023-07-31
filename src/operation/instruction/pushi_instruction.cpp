#include "operation.hpp"

#include <iostream>

class PushIInstruction: public Operation {
    public:
        PushIInstruction(Asm &stackMachine, any value) 
            : Operation(stackMachine, OperationType::INSTRUCTION, Opcode::PushI, value)
        {}

        void execute() {
            std::cout << "PushI executing" << std::endl;
        }
};