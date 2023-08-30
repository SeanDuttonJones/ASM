#ifndef DEFAULT_INITIALIZERS
#define DEFAULT_INITIALIZERS

#include "operation_initializer_interface.h"
#include "opcode.h"

class PushIInitializer : public IOperationInitializer {
    public:
        Operation* init(Opcode opcode, std::any operand);
};

class PushFInitializer : public IOperationInitializer {
    public:
        Operation* init(Opcode opcode, std::any operand);
};

class AddIInitializer : public IOperationInitializer {
    public:
        Operation* init(Opcode opcode, std::any operand);
};

class PStackInitializer : public IOperationInitializer {
    public:
        Operation* init(Opcode opcode, std::any operand);
};

class PMemInitializer : public IOperationInitializer {
    public:
        Operation* init(Opcode opcode, std::any operand);
};

class StoreCInitializer : public IOperationInitializer {
    public:
        Operation* init(Opcode opcode, std::any operand);
};

class StoreIInitializer : public IOperationInitializer {
    public:
        Operation* init(Opcode opcode, std::any operand);
};

class StoreFInitializer : public IOperationInitializer {
    public:
        Operation* init(Opcode opcode, std::any operand);
};

class LoadCInitializer : public IOperationInitializer {
    public:
        Operation* init(Opcode opcode, std::any operand);
};

class LoadIInitializer : public IOperationInitializer {
    public:
        Operation* init(Opcode opcode, std::any operand);
};

class LoadFInitializer : public IOperationInitializer {
    public:
        Operation* init(Opcode opcode, std::any operand);
};

#endif