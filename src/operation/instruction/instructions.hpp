#ifndef INSTRUCTIONS_CLASS_H
#define INSTRUCTIONS_CLASS_H

#include "operation.hpp"

class PushIInstruction : public Operation {
    public:
        PushIInstruction(std::stack<std::any> *stack, any value);
        void install();
        void execute();
};

#endif