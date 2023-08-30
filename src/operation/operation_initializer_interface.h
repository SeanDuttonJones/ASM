#ifndef OPERATION_INITIALIZER_INTERFACE
#define OPERATION_INITIALIZER_INTERFACE

#include <vector>
#include <any>

#include "operation.hpp"
#include "context_interface.hpp"
#include "opcode.h"

class IOperationInitializer {
    public:
        virtual Operation* init(NewOpcode opcode, std::any operand) = 0;
};

#endif