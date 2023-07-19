#ifndef ASM_OPERATION_H
#define ASM_OPERATION_H

#include <any>
#include "AsmOpcodes.hpp"

using namespace std;

class ASMOperation {
    private:
        Opcode opcode;
        any value;
    public:
        ASMOperation(Opcode opcode);
        ASMOperation(Opcode opcode, any value);
        Opcode getOpcode();
        any getValue();
};

#endif