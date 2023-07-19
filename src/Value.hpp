#ifndef ASM_VALUE_H
#define ASM_VALUE_H

enum class Type {BOOL, CHAR, INT, FLOAT, OTHER};

template <class T>
class Value {
    private:
        T value;
        Type type;
    public:
        Value(T value, Type type);
        bool isType(Type);
        T getValue();
};

template <class T>
Value<T>::Value(T value, Type type) {
    this->value = value;
    this->type = type;
}

template <class T>
bool Value<T>::isType(Type type) {
    return false;
}

template <class T>
T Value<T>::getValue() {
    return 0;
}

#endif