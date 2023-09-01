#ifndef DEFAULT_PC_ACCESS_ABC
#define DEFAULT_PC_ACCESS_ABC

#include "pc_access_interface.hpp"

class DefaultPCAccess : public IPCAccess {
    private:
        uint64_t *pc;
    
    public:
        DefaultPCAccess(uint64_t *pc);

        virtual uint64_t get();
        virtual void set(uint64_t newPC);

        virtual void increment();
        virtual void decrement();
};

#endif