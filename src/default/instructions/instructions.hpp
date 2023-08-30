#ifndef INSTRUCTIONS_CLASS_H
#define INSTRUCTIONS_CLASS_H

#include "operation.hpp"

class PushIInstruction : public Operation {
    public:
        PushIInstruction(NewOpcode opcode, std::any operand);
        void execute(IContext *context);
};

class AddIInstruction : public Operation {
    public:
        AddIInstruction(NewOpcode opcode, std::any operand);
        void execute(IContext *context);
};

class PStackInstruction : public Operation {
    private:
        std::string anyToString(std::any value);

    public:
        PStackInstruction(NewOpcode opcode, std::any operand);
        void execute(IContext *context);
};

#endif