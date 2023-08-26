#ifndef INSTRUCTIONS_CLASS_H
#define INSTRUCTIONS_CLASS_H

#include "operation.hpp"

class PushIInstruction : public Operation {
    public:
        PushIInstruction(IContext *context, any value);
        void install();
        void execute();
};

class AddIInstruction : public Operation {
    public:
        AddIInstruction(IContext *context);
        void install();
        void execute();
};

class PStackInstruction : public Operation {
    private:
        string anyToString(std::any value);
    
    public:
        PStackInstruction(IContext *context);
        void install();
        void execute();
};

#endif