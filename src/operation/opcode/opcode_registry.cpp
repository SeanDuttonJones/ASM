#include "opcode_registry.h"

#include <iostream>

OpcodeRegistry* OpcodeRegistry::pInstance = NULL;

OpcodeRegistry::OpcodeRegistry() {}

OpcodeRegistry* OpcodeRegistry::getInstance() {
    if(pInstance == NULL) {
        pInstance = new OpcodeRegistry();
        return pInstance;
    }

    return pInstance;
}

void OpcodeRegistry::registerOp(NewOpcode opcode) {
    uint32_t numberCode = opcode.getNumberCode();
    registry.insert({numberCode, opcode});
    textRegistry.insert({opcode.getTextCode(), numberCode});
}

NewOpcode OpcodeRegistry::retrieveOp(uint32_t opcode) {
    if(auto search = registry.find(opcode); search != registry.end()) {
        return search->second;
    }

    cerr << "Unable to find Opcode with value: " << opcode << endl;
}

NewOpcode OpcodeRegistry::retrieveOp(std::string opcode) {
    if(auto textSearch = textRegistry.find(opcode); textSearch != textRegistry.end()) {
        if(auto numSearch = registry.find(textSearch->second); numSearch != registry.end()) {
            return numSearch->second;
        }
    }

    cerr << "Unable to find Opcode with value: " << opcode << endl;
}