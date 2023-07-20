#ifndef ASM_OPERATION_H
#define ASM_OPERATION_H

#include <iostream>
#include <any>
#include <typeindex>
#include "Type.hpp"
#include "Opcode.hpp"

class ASMOperation {
    private:
        Opcode opcode;
        std::any value;
        Type type;

    public:
        ASMOperation(Opcode opcode);
        ASMOperation(Opcode opcode, std::any value);
        
        Opcode getOpcode();
        std::any getValue();
        Type getType();
        std::string toString();
};

#endif