#include "default_pc_access.hpp"

DefaultPCAccess::DefaultPCAccess(uint64_t *pc) {
    this->pc = pc;
}

uint64_t DefaultPCAccess::get() {
    return *pc;
}

void DefaultPCAccess::set(uint64_t npc) {
    *pc = npc;
}

void DefaultPCAccess::increment() {
    (*pc)++;
}

void DefaultPCAccess::decrement() {
    (*pc)--;
}