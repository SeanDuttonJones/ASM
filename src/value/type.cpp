#include "type.h"

std::map<std::type_index, Type> TypeTools::typeMap = {
    {std::type_index(typeid(bool)), Type::BOOL},
    {std::type_index(typeid(char)), Type::CHAR},
    {std::type_index(typeid(int)), Type::INT},
    {std::type_index(typeid(unsigned int)), Type::UNSIGNED_INT},
    {std::type_index(typeid(float)), Type::FLOAT},
    {std::type_index(typeid(double)), Type::DOUBLE},
    {std::type_index(typeid(std::string)), Type::STRING},
    {std::type_index(typeid(void)), Type::NONE}
};

std::map<Type, std::string> TypeTools::typeStringMap = {
    {Type::BOOL, "Boolean"},
    {Type::CHAR, "Character"},
    {Type::INT, "Integer"},
    {Type::UNSIGNED_INT, "UInteger"},
    {Type::FLOAT, "Float"},
    {Type::DOUBLE, "Double"},
    {Type::STRING, "String"},
    {Type::NONE, "None"}
};

Type TypeTools::getType(std::type_index index) {
    std::map<std::type_index, Type>::iterator it = typeMap.find(index);
    if(it != typeMap.end()) {
        return it->second;
    }

    return Type::NONE;
};

std::string TypeTools::toString(Type type) {
    std::map<Type, std::string>::iterator it = typeStringMap.find(type);
    if(it != typeStringMap.end()) {
        return it->second;
    }

    return typeStringMap[Type::NONE];
}