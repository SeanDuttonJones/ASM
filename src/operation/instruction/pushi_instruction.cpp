#include "operation.hpp"

#include <iostream>

class PushIInstruction: public Operation {
    public:
        PushIInstruction(Asm &stackMachine, any value) 
            : Operation(stackMachine, OperationType::INSTRUCTION, Opcode::PushI, value)
        {}

        void install() {
            std::cout << "PushI: installing" << std::endl;
        }

        void execute() {
            std::cout << "PushI: executing" << std::endl;
        }
};