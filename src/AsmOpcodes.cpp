#include "AsmOpcodes.hpp"
#include <string>

Opcode AsmOpcode::getOpcode(string s) {
    map<string, Opcode>::iterator it = opcodeMap.find(s);
    if(it != opcodeMap.end()) {
        return it->second;
    }

    return Opcode::Error;
}