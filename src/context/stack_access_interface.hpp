#ifndef ABS_STACK_ACCESS_CLASS
#define ABS_STACK_ACCESS_CLASS

#include <cstdint>

template <class T> class IStackAccess {
    public:
        virtual void push(T data) = 0;
        virtual T pop() = 0;
        virtual uint32_t size() = 0;
        virtual bool empty() = 0;
};

#endif