#ifndef DEFAULT_INITIALIZERS
#define DEFAULT_INITIALIZERS

#include "operation_initializer_interface.h"
#include "opcode.h"

/*
==================
=   ARITHMETIC   =
==================
*/
class AddIInitializer : public IOperationInitializer {
    public:
        Operation* init(Opcode opcode, std::any operand);
};

class SubIInitializer : public IOperationInitializer {
    public:
        Operation* init(Opcode opcode, std::any operand);
};

class NegIInitializer : public IOperationInitializer {
    public:
        Operation* init(Opcode opcode, std::any operand);
};

class MulIInitializer : public IOperationInitializer {
    public:
        Operation* init(Opcode opcode, std::any operand);
};

class DivIInitializer : public IOperationInitializer {
    public:
        Operation* init(Opcode opcode, std::any operand);
};

class ModIInitializer : public IOperationInitializer {
    public:
        Operation* init(Opcode opcode, std::any operand);
};

class AddFInitializer : public IOperationInitializer {
    public:
        Operation* init(Opcode opcode, std::any operand);
};

class SubFInitializer : public IOperationInitializer {
    public:
        Operation* init(Opcode opcode, std::any operand);
};

class NegFInitializer : public IOperationInitializer {
    public:
        Operation* init(Opcode opcode, std::any operand);
};

class MulFInitializer : public IOperationInitializer {
    public:
        Operation* init(Opcode opcode, std::any operand);
};

class DivFInitializer : public IOperationInitializer {
    public:
        Operation* init(Opcode opcode, std::any operand);
};


/*
===================
=      STACK      =
===================
*/
class PushIInitializer : public IOperationInitializer {
    public:
        Operation* init(Opcode opcode, std::any operand);
};

class PushFInitializer : public IOperationInitializer {
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


/*
==================
=     HELPER     =
==================
*/
class PStackInitializer : public IOperationInitializer {
    public:
        Operation* init(Opcode opcode, std::any operand);
};

class PMemInitializer : public IOperationInitializer {
    public:
        Operation* init(Opcode opcode, std::any operand);
};

#endif