#ifndef DEFAULT_INITIALIZERS
#define DEFAULT_INITIALIZERS

#include "operation_initializer_interface.h"
#include "opcode.h"

class PushIInitializer : public IOperationInitializer {
    public:
        Operation* init(NewOpcode opcode, std::any operand);
};

class AddIInitializer : public IOperationInitializer {
    public:
        Operation* init(NewOpcode opcode, std::any operand);
};

class PStackInitializer : public IOperationInitializer {
    public:
        Operation* init(NewOpcode opcode, std::any operand);
};

#endif