#ifndef VALUE_CLASS_H
#define VALUE_CLASS_H

#include <any>

enum class Type {
    CHAR,
    INT,
    FLOAT
};

class Value {
    private:
        Type type;
        std::any value;

    public:
        Value(std::any value, Type type);

        Type getType();
        std::any getValue();
        void setValue(std::any value);

};

#endif