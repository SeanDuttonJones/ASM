#include <iostream>
#include <array>
#include <charconv>

#include "asm.h"
#include "loader.h"
#include "operation_factory.h"
#include "operation.h"
#include "opcode_registry.h"
#include "initializers.h"
#include "opcode.h"
#include "type.h"

using namespace std;

int main() {
    // array<unsigned char, 32> memory;
    
    // // LOADING VALUE INTO MEMORY
    // float f = 3.14f;
    // unsigned char const *p = reinterpret_cast<unsigned char const *>(&f);
    
    // for(std::size_t i = 0; i != sizeof(float); ++i) {
    //     // std::printf("The byte #%zu is 0x%02X\n", i, p[i]);
    //     memory[i] = p[i];
    // }

    // for(std::size_t i = 0; i < 32; i++) {
    //     std::printf("MEMORY: byte #%zu is 0x%02X\n", i, memory[i]);
    // }

    // // READING VALUE FROM MEMORY
    // float k = 0;
    // unsigned char *kp = reinterpret_cast<unsigned char *>(&k);
    // for(std::size_t i = 0; i != sizeof(float); ++i) {
    //     kp[i] = memory[i];
    //     std::printf("The byte #%zu is 0x%02X\n", i, kp[i]);
    // }

    // cout << "K: " << k << endl;

    OpcodeRegistry *opcodeRegistry = new OpcodeRegistry();
    OperationFactory *operationFactory = new OperationFactory();

    // PushI Instruction
    Opcode pushIOp(OperationType::INSTRUCTION, "PushI", Type::INT);
    IOperationInitializer *pushIInitializer = new PushIInitializer();

    opcodeRegistry->registerOp(pushIOp);
    operationFactory->registerOp(pushIOp, pushIInitializer);

    // AddI Instruction
    Opcode addIOp(OperationType::INSTRUCTION, "AddI", Type::INT);
    IOperationInitializer *addIInitializer = new AddIInitializer();

    opcodeRegistry->registerOp(addIOp);
    operationFactory->registerOp(addIOp, addIInitializer);

    // PStack Instruction
    Opcode pStackOp(OperationType::INSTRUCTION, "PStack", Type::NONE);
    IOperationInitializer *pStackInitializer = new PStackInitializer();

    opcodeRegistry->registerOp(pStackOp);
    operationFactory->registerOp(pStackOp, pStackInitializer);

    Asm *stackMachine = new Asm();

    Loader loader(stackMachine, opcodeRegistry, operationFactory);
    cout << "LOADING..." << endl;
    loader.load("./input/test.asm");
    cout << "LOADING COMPLETE!\n" << endl;
    
    cout << "STARTING STACK MACHINE..." << endl;
    stackMachine->start();
    cout << "STACK MACHINE FINISHED!" << endl;
    
    delete stackMachine;
};