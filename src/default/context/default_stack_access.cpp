#include "default_stack_access.hpp"

DefaultStackAccess::DefaultStackAccess(std::stack<std::any> *stack) {
    this->stack = stack;
}

std::any DefaultStackAccess::top() {
    return stack->top();
}

bool DefaultStackAccess::empty() {
    return stack->empty();
}

uint64_t DefaultStackAccess::size() {
    return stack->size();
}

void DefaultStackAccess::push(std::any data) {
    stack->push(data);
}

void DefaultStackAccess::pop() {
    stack->pop();
}