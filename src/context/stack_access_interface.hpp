#ifndef ABS_STACK_ACCESS_CLASS
#define ABS_STACK_ACCESS_CLASS

#include <cstdint>

template <class T> class IStackAccess {
    public:
        virtual T top() = 0;

        virtual bool empty() = 0;
        virtual uint64_t size() = 0;

        virtual void push(T data) = 0;
        virtual void pop() = 0;
};

#endif