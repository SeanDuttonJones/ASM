#ifndef ASM_OPCODES_H
#define ASM_OPCODES_H

#include <string>
#include <map>

using namespace std;

enum class Opcode {
    PushI,
    Add,
    Subtract,
    Multiply,
    Divide,
    PStack,
    Error
};

class AsmOpcode {
    public:
        inline static map<string, Opcode> opcodeMap = {
            {"PushI", Opcode::PushI},
            {"Add", Opcode::Add}
        };
        static Opcode getOpcode(string s);
};

#endif