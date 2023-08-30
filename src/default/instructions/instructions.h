#ifndef INSTRUCTIONS_CLASS_H
#define INSTRUCTIONS_CLASS_H

#include "operation.h"

class PushIInstruction : public Operation {
    public:
        PushIInstruction(Opcode opcode, std::any operand);
        void execute(IContext *context);
};

class PushFInstruction : public Operation {
    public:
        PushFInstruction(Opcode opcode, std::any operand);
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

class PMemInstruction : public Operation {
    public:
        PMemInstruction(Opcode opcode, std::any operand);
        void execute(IContext *context);
};

class StoreCInstruction : public Operation {
    public:
        StoreCInstruction(Opcode opcode, std::any operand);
        void execute(IContext *context);
};

class StoreIInstruction : public Operation {
    public:
        StoreIInstruction(Opcode opcode, std::any operand);
        void execute(IContext *context);
};

class StoreFInstruction : public Operation {
    public:
        StoreFInstruction(Opcode opcode, std::any operand);
        void execute(IContext *context);
};

class LoadCInstruction : public Operation {
    public:
        LoadCInstruction(Opcode opcode, std::any operand);
        void execute(IContext *context);
};

class LoadIInstruction : public Operation {
    public:
        LoadIInstruction(Opcode opcode, std::any operand);
        void execute(IContext *context);
};

class LoadFInstruction : public Operation {
    public:
        LoadFInstruction(Opcode opcode, std::any operand);
        void execute(IContext *context);
};

#endif