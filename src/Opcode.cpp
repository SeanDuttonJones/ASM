#include "Opcode.hpp"

std::map<std::string, Opcode> OpcodeTools::opcodeMap = {
    {"PushI", Opcode::PushI},
    {"Add", Opcode::Add}
};

std::map<Opcode, std::string> OpcodeTools::opcodeStringMap = {
    {Opcode::PushI, "PushI"},
    {Opcode::Add, "Add"},
    {Opcode::Error, "Error"}
};

Opcode OpcodeTools::getOpcode(std::string s) {
    std::map<std::string, Opcode>::iterator it = opcodeMap.find(s);
    if(it != opcodeMap.end()) {
        return it->second;
    }

    return Opcode::Error;
}

std::string OpcodeTools::toString(Opcode opcode) {
    std::map<Opcode, std::string>::iterator it = opcodeStringMap.find(opcode);
    if(it != opcodeStringMap.end()) {
        return it->second;
    }

    return opcodeStringMap[Opcode::Error];
}