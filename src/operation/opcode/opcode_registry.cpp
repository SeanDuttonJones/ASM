#include "opcode_registry.h"

void OpcodeRegistry::registerOp(Opcode opcode) {
    registry.insert({opcode.getCode(), opcode});
}

Opcode OpcodeRegistry::retrieveOp(std::string opcode) {
    return registry.at(opcode);
}