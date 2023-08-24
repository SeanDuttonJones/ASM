#ifndef VALUE_CLASS_H
#define VALUE_CLASS_H

#include <any>

enum class ValueType {
    CHAR,
    INT,
    FLOAT,
    LABEL
};

class Value {
    private:
        ValueType type;
        std::any value;

    public:
        Value(std::any value, ValueType type);

        ValueType getType();
        std::any getValue();
        void setValue(std::any value);

};

#endif