#ifndef ASM_TYPE_H
#define ASM_TYPE_H

#include <typeindex>
#include <map>


// Technically only need:
// CHARACTER    : 1 byte
// INTEGER      : 4 bytes
// FLOAT        : 8 bytes
// STRING       : special type for handling label Operations
// BOOLEAN      : special type for debugging. SHOULD NOT BE USED
enum class Type {
    CHARACTER,
    INTEGER,
    FLOAT,
    STRING,
    BOOLEAN,
    NONE,
};

class TypeTools {
    private:
        static std::map<std::type_index, Type> typeMap;
        static std::map<Type, std::string> typeStringMap;
    
    public:
        static Type getType(std::type_index);
        static std::string toString(Type);

};

#endif