#ifndef INSTRUCTIONS_CLASS_H
#define INSTRUCTIONS_CLASS_H

#include "operation.h"

/*
    ==================
    =   ARITHMETIC   =
    ==================
*/
class AddIInstruction : public Operation {
    public:
        AddIInstruction(Opcode opcode, std::any operand);
        void execute(IContext *context);
};

class SubIInstruction : public Operation {
    public:
        SubIInstruction(Opcode opcode, std::any operand);
        void execute(IContext *context);
};

class NegIInstruction : public Operation {
    public:
        NegIInstruction(Opcode opcode, std::any operand);
        void execute(IContext *context);
};

class MulIInstruction : public Operation {
    public:
        MulIInstruction(Opcode opcode, std::any operand);
        void execute(IContext *context);
};

class DivIInstruction : public Operation {
    public:
        DivIInstruction(Opcode opcode, std::any operand);
        void execute(IContext *context);
};

class ModIInstruction : public Operation {
    public:
        ModIInstruction(Opcode opcode, std::any operand);
        void execute(IContext *context);
};

class AddFInstruction : public Operation {
    public:
        AddFInstruction(Opcode opcode, std::any operand);
        void execute(IContext *context);
};

class SubFInstruction : public Operation {
    public:
        SubFInstruction(Opcode opcode, std::any operand);
        void execute(IContext *context);
};

class NegFInstruction : public Operation {
    public:
        NegFInstruction(Opcode opcode, std::any operand);
        void execute(IContext *context);
};

class MulFInstruction : public Operation {
    public:
        MulFInstruction(Opcode opcode, std::any operand);
        void execute(IContext *context);
};

class DivFInstruction : public Operation {
    public:
        DivFInstruction(Opcode opcode, std::any operand);
        void execute(IContext *context);
};


/*
    ===================
    =      STACK      =
    ===================
*/
class DupInstruction : public Operation {
    public:
        DupInstruction(Opcode opcode, std::any operand);
        void execute(IContext *context);
};

class ExchInstruction : public Operation {
    public:
        ExchInstruction(Opcode opcode, std::any operand);
        void execute(IContext *context);
};

class PopInstruction : public Operation {
    public:
        PopInstruction(Opcode opcode, std::any operand);
        void execute(IContext *context);
};

class PushIInstruction : public Operation {
    public:
        PushIInstruction(Opcode opcode, std::any operand);
        void execute(IContext *context);
};

class PushDInstruction : public Operation {
    public:
        PushDInstruction(Opcode opcode, std::any operand);
        void execute(IContext *context);
};

class PushFInstruction : public Operation {
    public:
        PushFInstruction(Opcode opcode, std::any operand);
        void execute(IContext *context);
};

class PushPCInstruction : public Operation {
    public:
        PushPCInstruction(Opcode opcode, std::any operand);
        void execute(IContext *context);
};

class PopPCInstruction : public Operation {
    public:
        PopPCInstruction(Opcode opcode, std::any operand);
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

class MtopInstruction : public Operation {
    public:
        MtopInstruction(Opcode opcode, std::any operand);
        void execute(IContext *context);
};


/*
    ==========================
    =      CONTROL FLOW      =
    ==========================
*/

class LabelInstruction : public Operation {
    public:
        LabelInstruction(Opcode opcode, std::any operand);
        void execute(IContext *context);
};

class JumpInstruction : public Operation {
    public:
        JumpInstruction(Opcode opcode, std::any operand);
        void execute(IContext *context);
};

class JumpPInstruction : public Operation {
    public:
        JumpPInstruction(Opcode opcode, std::any operand);
        void execute(IContext *context);
};

/*
    ==================
    =     HELPER     =
    ==================
*/
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

#endif