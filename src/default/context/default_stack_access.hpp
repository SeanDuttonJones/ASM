#ifndef DEFAULT_STACK_ACCESS_CLASS
#define DEFAULT_STACK_ACCESS_CLASS

#include <stack>
#include <any>

#include "stack_access_interface.hpp"

class DefaultStackAccess : public IStackAccess {
    private:
        std::stack<std::any> *stack;

    public:
        DefaultStackAccess(std::stack<std::any> *stack);

        std::any top();

        bool empty();
        uint64_t size();

        void push(std::any data);
        void pop();
};

#endif