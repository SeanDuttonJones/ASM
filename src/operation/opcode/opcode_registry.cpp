#include "opcode_registry.h"

void OpcodeRegistry::registerOp(NewOpcode opcode) {
    registry.insert({opcode.getCode(), opcode});
}

NewOpcode OpcodeRegistry::retrieveOp(std::string opcode) {
    return registry.at(opcode);
}