#include "value.hpp"

Value::Value(std::any value, ValueType type) {
    this->value = value;
    this->type = type;
}

std::any Value::getValue() {
    return value;
}

void Value::setValue(std::any value) {
    this->value = value;
}

ValueType Value::getType() {
    return type;
}