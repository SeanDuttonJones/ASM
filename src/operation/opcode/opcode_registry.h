#ifndef OPCODE_REGISTRY_CLASS
#define OPCODE_REGISTRY_CLASS

#include <string>
#include <unordered_map>

#include "opcode.h"

class OpcodeRegistry {
    private:
        std::unordered_map<std::string, Opcode> registry;

    public:
        void registerOp(Opcode opcode);
        Opcode retrieveOp(std::string opcode);
};

#endif