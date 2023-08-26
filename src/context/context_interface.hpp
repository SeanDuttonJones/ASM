#ifndef ABS_CONTEXT_CLASS
#define ABS_CONTEXT_CLASS

#include <any>

#include "stack_access_interface.hpp"
#include "memory_access_interface.hpp"

class IContext {
    public:
        virtual IStackAccess* getStackAccess() = 0;
        virtual IMemoryAccess* getMemoryAccess() = 0;
};

#endif