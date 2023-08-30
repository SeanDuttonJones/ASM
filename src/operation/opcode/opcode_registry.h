#ifndef OPCODE_REGISTRY_CLASS
#define OPCODE_REGISTRY_CLASS

#include <string>
#include <unordered_map>

#include "opcode.h"

class OpcodeRegistry {
    private:
        std::unordered_map<std::string, NewOpcode> registry;

    public:
        void registerOp(NewOpcode opcode);
        NewOpcode retrieveOp(std::string opcode);
};

#endif