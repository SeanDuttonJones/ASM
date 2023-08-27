#ifndef OPCODE_REGISTRY_CLASS
#define OPCODE_REGISTRY_CLASS

#include <string>
#include <map>

#include "opcode.h"

class OpcodeRegistry {
    private:
        static OpcodeRegistry* pInstance;
        OpcodeRegistry();
        
        std::map<uint32_t, NewOpcode> registry;
        std::map<std::string, u_int32_t> textRegistry;

    public:
        OpcodeRegistry(OpcodeRegistry &other) = delete;
        void operator=(const OpcodeRegistry &) = delete;

        static OpcodeRegistry* getInstance();
        
        void registerOp(NewOpcode opcode);
        
        NewOpcode retrieveOp(uint32_t opcode);
        NewOpcode retrieveOp(std::string opcode);
};

#endif