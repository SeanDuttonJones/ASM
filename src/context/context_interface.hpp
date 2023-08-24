#ifndef ABS_CONTEXT_CLASS
#define ABS_CONTEXT_CLASS

#include "stack_access_interface.hpp"
#include "memory_access_interface.hpp"

class IContext {
    public:
        template <class T>
        IStackAccess<T>* getStackAccess();
        virtual IMemoryAccess* getMemoryAccess() = 0;
};

#endif