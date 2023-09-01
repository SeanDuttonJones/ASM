#ifndef DEFAULT_CONTEXT_CLASS
#define DEFAULT_CONTEXT_CLASS

#include <any>

#include "context_interface.hpp"
#include "default_stack_access.hpp"
#include "default_memory_access.hpp"
#include "default_pc_access.hpp"

class DefaultContext : public IContext {
    private:
        DefaultStackAccess *stackAccessor;
        DefaultMemoryAccess *memoryAccessor;
        DefaultPCAccess *pcAccessor;
        
    public:
        DefaultContext(DefaultStackAccess *stackAccessor, DefaultMemoryAccess *memoryAccessor, DefaultPCAccess *pcAccessor);

        DefaultStackAccess* getStackAccess();
        DefaultMemoryAccess* getMemoryAccess();
        DefaultPCAccess* getPCAccess();
};

#endif