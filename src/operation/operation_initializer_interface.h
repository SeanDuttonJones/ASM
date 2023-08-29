#ifndef OPERATION_INITIALIZER_INTERFACE
#define OPERATION_INITIALIZER_INTERFACE

#include <vector>
#include <any>

#include "operation.hpp"
#include "context_interface.hpp"

class IOperationInitializer {
    public:
        virtual Operation* init(IContext *context, std::vector<std::any> operands) = 0;
};

#endif