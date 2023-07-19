#ifndef ASM_OPERATION_H
#define ASM_OPERATION_H

#include <any>
#include "AsmOpcodes.hpp"
#include "Type.hpp"

class ASMOperation {
    private:
        Opcode opcode;
        any value;
        Type type;

    public:
        ASMOperation(Opcode opcode);
        ASMOperation(Opcode opcode, any value);
        
        Opcode getOpcode();
        any getValue();
        Type getType();
};

#endif