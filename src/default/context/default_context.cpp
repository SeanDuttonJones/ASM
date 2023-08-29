#include "default_context.hpp"

DefaultContext::DefaultContext(DefaultStackAccess *stackAccessor, DefaultMemoryAccess *memoryAccessor) {
    this->stackAccessor = stackAccessor;
    this->memoryAccessor = memoryAccessor;
}

DefaultStackAccess* DefaultContext::getStackAccess() {
    return stackAccessor;
}

DefaultMemoryAccess* DefaultContext::getMemoryAccess() {
    return memoryAccessor;
}