#ifndef DEFAULT_CONTEXT_CLASS
#define DEFAULT_CONTEXT_CLASS

#include <any>

#include "context_interface.hpp"
#include "default_stack_access.hpp"
#include "default_memory_access.hpp"

class DefaultContext : public IContext {
    private:
        DefaultStackAccess *stackAccessor;
        DefaultMemoryAccess *memoryAccessor;
        
    public:
        DefaultContext(DefaultStackAccess *stackAccessor, DefaultMemoryAccess *memoryAccessor);

        DefaultStackAccess* getStackAccess();
        DefaultMemoryAccess* getMemoryAccess();
};

#endif