#include "Type.hpp"

std::map<std::type_index, Type> TypeTools::typeMap = {
    {std::type_index(typeid(bool)), Type::BOOLEAN},
    {std::type_index(typeid(char)), Type::CHARACTER},
    {std::type_index(typeid(int)), Type::INTEGER},
    {std::type_index(typeid(char*)), Type::STRING},
    {std::type_index(typeid(float)), Type::FLOAT},
    {std::type_index(typeid(void)), Type::NONE}
};

std::map<Type, std::string> TypeTools::typeStringMap = {
    {Type::BOOLEAN, "Boolean"},
    {Type::CHARACTER, "Character"},
    {Type::INTEGER, "Integer"},
    {Type::STRING, "String"},
    {Type::FLOAT, "Float"},
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