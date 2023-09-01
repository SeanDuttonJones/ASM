#include "default_context.hpp"

DefaultContext::DefaultContext(DefaultStackAccess *stackAccessor, 
        DefaultMemoryAccess *memoryAccessor, DefaultPCAccess *pcAccessor) {
    
    this->stackAccessor = stackAccessor;
    this->memoryAccessor = memoryAccessor;
    this->pcAccessor = pcAccessor;
}

DefaultStackAccess* DefaultContext::getStackAccess() {
    return stackAccessor;
}

DefaultMemoryAccess* DefaultContext::getMemoryAccess() {
    return memoryAccessor;
}

DefaultPCAccess* DefaultContext::getPCAccess() {
    return pcAccessor;
}