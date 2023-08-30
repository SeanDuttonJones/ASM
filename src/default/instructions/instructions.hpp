#ifndef INSTRUCTIONS_CLASS_H
#define INSTRUCTIONS_CLASS_H

#include "operation.h"

class PushIInstruction : public Operation {
    public:
        PushIInstruction(Opcode opcode, std::any operand);
        void execute(IContext *context);
};

class AddIInstruction : public Operation {
    public:
        AddIInstruction(Opcode opcode, std::any operand);
        void execute(IContext *context);
};

class PStackInstruction : public Operation {
    private:
        std::string anyToString(std::any value);

    public:
        PStackInstruction(Opcode opcode, std::any operand);
        void execute(IContext *context);
};

#endif