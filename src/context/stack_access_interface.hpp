#ifndef ABS_STACK_ACCESS_CLASS
#define ABS_STACK_ACCESS_CLASS

#include <cstdint>
#include <any>

class IStackAccess {
    public:
        virtual std::any top() = 0;

        virtual bool empty() = 0;
        virtual uint64_t size() = 0;

        virtual void push(std::any data) = 0;
        virtual void pop() = 0;
};

#endif