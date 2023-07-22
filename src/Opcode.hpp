#ifndef ASM_OPCODE_H
#define ASM_OPCODE_H

#include <map>

enum class Opcode {
    PushI,
    DLabel,
    Add,
    Subtract,
    Multiply,
    Divide,
    PStack,
    Error
};

class OpcodeTools {
    private:
        static std::map<std::string, Opcode> opcodeMap;
        static std::map<Opcode, std::string> opcodeStringMap;
    
    public:
        static Opcode getOpcode(std::string s);
        static std::string toString(Opcode opcode);
};

#endif