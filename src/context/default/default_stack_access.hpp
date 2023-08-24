#ifndef DEFAULT_STACK_ACCESS_CLASS
#define DEFAULT_STACK_ACCESS_CLASS

#include <stack>
#include <any>

#include "stack_access_interface.hpp"

class DefaultStackAccess : public IStackAccess<std::any> {
    public:
        DefaultStackAccess(std::stack<std::any> *stack);
        
        void push(std::any data) ;
        std::any pop();
        
        std::uint32_t size();
        bool empty();
};

#endif