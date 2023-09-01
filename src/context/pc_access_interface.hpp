#ifndef PC_ACCESS_ABC
#define PC_ACCESS_ABC

#include <cstdint>

class IPCAccess {
    public:
        virtual uint64_t get() = 0;
        virtual void set(uint64_t pc) = 0;

        virtual void increment() = 0;
        virtual void decrement() = 0;
};

#endif