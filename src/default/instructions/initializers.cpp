#include "initializers.h"
#include "instructions.h"

/*
    ==================
    =   ARITHMETIC   =
    ==================
*/
Operation* AddIInitializer::init(Opcode opcode, std::any operand) {
    return new AddIInstruction(opcode, operand);
}

Operation* SubIInitializer::init(Opcode opcode, std::any operand) {
    return new SubIInstruction(opcode, operand);
}

Operation* NegIInitializer::init(Opcode opcode, std::any operand) {
    return new NegIInstruction(opcode, operand);
}

Operation* MulIInitializer::init(Opcode opcode, std::any operand) {
    return new MulIInstruction(opcode, operand);
}

Operation* DivIInitializer::init(Opcode opcode, std::any operand) {
    return new DivIInstruction(opcode, operand);
}

Operation* ModIInitializer::init(Opcode opcode, std::any operand) {
    return new ModIInstruction(opcode, operand);
}

Operation* AddFInitializer::init(Opcode opcode, std::any operand) {
    return new AddFInstruction(opcode, operand);
}

Operation* SubFInitializer::init(Opcode opcode, std::any operand) {
    return new SubFInstruction(opcode, operand);
}

Operation* NegFInitializer::init(Opcode opcode, std::any operand) {
    return new NegFInstruction(opcode, operand);
}

Operation* MulFInitializer::init(Opcode opcode, std::any operand) {
    return new MulFInstruction(opcode, operand);
}

Operation* DivFInitializer::init(Opcode opcode, std::any operand) {
    return new DivFInstruction(opcode, operand);
}


/*
    ===================
    =      STACK      =
    ===================
*/
Operation* DupInitializer::init(Opcode opcode, std::any operand) {
    return new DupInstruction(opcode, operand);
}

Operation* ExchInitializer::init(Opcode opcode, std::any operand) {
    return new ExchInstruction(opcode, operand);
}

Operation* PopInitializer::init(Opcode opcode, std::any operand) {
    return new PopInstruction(opcode, operand);
}

Operation* PushIInitializer::init(Opcode opcode, std::any operand) {
    return new PushIInstruction(opcode, operand);
}

Operation* PushDInitializer::init(Opcode opcode, std::any operand) {
    return new PushDInstruction(opcode, operand);
}

Operation* PushFInitializer::init(Opcode opcode, std::any operand) {
    return new PushFInstruction(opcode, operand);
}

Operation* PushPCInitializer::init(Opcode opcode, std::any operand) {
    return new PushPCInstruction(opcode, operand);
}

Operation* PopPCInitializer::init(Opcode opcode, std::any operand) {
    return new PopPCInstruction(opcode, operand);
}

Operation* StoreCInitializer::init(Opcode opcode, std::any operand) {
    return new StoreCInstruction(opcode, operand);
}

Operation* StoreIInitializer::init(Opcode opcode, std::any operand) {
    return new StoreIInstruction(opcode, operand);
}

Operation* StoreFInitializer::init(Opcode opcode, std::any operand) {
    return new StoreFInstruction(opcode, operand);
}

Operation* LoadCInitializer::init(Opcode opcode, std::any operand) {
    return new LoadCInstruction(opcode, operand);
}

Operation* LoadIInitializer::init(Opcode opcode, std::any operand) {
    return new LoadIInstruction(opcode, operand);
}

Operation* LoadFInitializer::init(Opcode opcode, std::any operand) {
    return new LoadFInstruction(opcode, operand);
}

Operation* MtopInitializer::init(Opcode opcode, std::any operand) {
    return new MtopInstruction(opcode, operand);
}


/*
    ==========================
    =      CONTROL FLOW      =
    ==========================
*/

Operation* LabelInitializer::init(Opcode opcode, std::any operand) {
    return new LabelInstruction(opcode, operand);
}

Operation* JumpInitializer::init(Opcode opcode, std::any operand) {
    return new JumpInstruction(opcode, operand);
}

Operation* JumpPInitializer::init(Opcode opcode, std::any operand) {
    return new JumpPInstruction(opcode, operand);
}

/*
    ==================
    =     HELPER     =
    ==================
*/
Operation* PStackInitializer::init(Opcode opcode, std::any operand) {
    return new PStackInstruction(opcode, operand);
}

Operation* PMemInitializer::init(Opcode opcode, std::any operand) {
    return new PMemInstruction(opcode, operand);
}