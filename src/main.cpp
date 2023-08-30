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

void createInstructions(OpcodeRegistry *opcodeRegistry, OperationFactory *operationFactory) {
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

    // PMem Instruction
    Opcode pMemOp(OperationType::INSTRUCTION, "PMem", Type::NONE);
    IOperationInitializer *pMemInitializer = new PMemInitializer();

    opcodeRegistry->registerOp(pMemOp);
    operationFactory->registerOp(pMemOp, pMemInitializer);

    // StoreI Instruction
    Opcode storeIOp(OperationType::INSTRUCTION, "StoreI", Type::INT);
    IOperationInitializer *storeIInitializer = new StoreIInitializer();

    opcodeRegistry->registerOp(storeIOp);
    operationFactory->registerOp(storeIOp, storeIInitializer);

    // LoadI Instruction
    Opcode loadIOp(OperationType::INSTRUCTION, "LoadI", Type::INT);
    IOperationInitializer *loadIInitializer = new LoadIInitializer();

    opcodeRegistry->registerOp(loadIOp);
    operationFactory->registerOp(loadIOp, loadIInitializer);
}

int main() {
    // vector<unsigned char> memory;
    
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

    OpcodeRegistry opcodeRegistry;
    OperationFactory operationFactory;

    createInstructions(&opcodeRegistry, &operationFactory);

    Asm stackMachine;

    Loader loader(&stackMachine, &opcodeRegistry, &operationFactory);
    loader.load("./input/test.asm");
    
    stackMachine.start();
};