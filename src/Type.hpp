#ifndef ASM_TYPE_H
#define ASM_TYPE_H

#include <typeindex>
#include <map>

enum class Type {
    BOOLEAN,
    CHARACTER,
    INTEGER,
    STRING,
    FLOAT,
    NONE
};

class TypeTools {
    private:
        static std::map<std::type_index, Type> typeMap;
        static std::map<Type, std::string> typeStringMap;
    
    public:
        static Type getType(std::type_index);
        static std::string getTypeName(Type);

};

#endif