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

    // PushF Instruction
    Opcode pushFOp(OperationType::INSTRUCTION, "PushF", Type::DOUBLE);
    IOperationInitializer *pushFInitializer = new PushFInitializer();

    opcodeRegistry->registerOp(pushFOp);
    operationFactory->registerOp(pushFOp, pushFInitializer);

    // AddI Instruction
    Opcode addIOp(OperationType::INSTRUCTION, "AddI", Type::NONE);
    IOperationInitializer *addIInitializer = new AddIInitializer();

    opcodeRegistry->registerOp(addIOp);
    operationFactory->registerOp(addIOp, addIInitializer);

    // SubI Instruction
    Opcode subIOp(OperationType::INSTRUCTION, "SubI", Type::NONE);
    IOperationInitializer *subIInitializer = new SubIInitializer();

    opcodeRegistry->registerOp(subIOp);
    operationFactory->registerOp(subIOp, subIInitializer);

    // NegI Instruction
    Opcode negIOp(OperationType::INSTRUCTION, "NegI", Type::NONE);
    IOperationInitializer *negIInitializer = new NegIInitializer();

    opcodeRegistry->registerOp(negIOp);
    operationFactory->registerOp(negIOp, negIInitializer);

    // MulI Instruction
    Opcode mulIOp(OperationType::INSTRUCTION, "MulI", Type::NONE);
    IOperationInitializer *mulIInitializer = new MulIInitializer();

    opcodeRegistry->registerOp(mulIOp);
    operationFactory->registerOp(mulIOp, mulIInitializer);

    // DivI Instruction
    Opcode divIOp(OperationType::INSTRUCTION, "DivI", Type::NONE);
    IOperationInitializer *divIInitializer = new DivIInitializer();

    opcodeRegistry->registerOp(divIOp);
    operationFactory->registerOp(divIOp, divIInitializer);

    // ModI Instruction
    Opcode modIOp(OperationType::INSTRUCTION, "ModI", Type::NONE);
    IOperationInitializer *modIInitializer = new ModIInitializer();

    opcodeRegistry->registerOp(modIOp);
    operationFactory->registerOp(modIOp, modIInitializer);

    // AddF Instruction
    Opcode addFOp(OperationType::INSTRUCTION, "AddF", Type::NONE);
    IOperationInitializer *addFInitializer = new AddFInitializer();

    opcodeRegistry->registerOp(addFOp);
    operationFactory->registerOp(addFOp, addFInitializer);

    // SubF Instruction
    Opcode subFOp(OperationType::INSTRUCTION, "SubF", Type::NONE);
    IOperationInitializer *subFInitializer = new SubFInitializer();

    opcodeRegistry->registerOp(subFOp);
    operationFactory->registerOp(subFOp, subFInitializer);

    // NegF Instruction
    Opcode negFOp(OperationType::INSTRUCTION, "NegF", Type::NONE);
    IOperationInitializer *negFInitializer = new NegFInitializer();

    opcodeRegistry->registerOp(negFOp);
    operationFactory->registerOp(negFOp, negFInitializer);

    // MulF Instruction
    Opcode mulFOp(OperationType::INSTRUCTION, "MulF", Type::NONE);
    IOperationInitializer *mulFInitializer = new MulFInitializer();

    opcodeRegistry->registerOp(mulFOp);
    operationFactory->registerOp(mulFOp, mulFInitializer);

    // DivF Instruction
    Opcode divFOp(OperationType::INSTRUCTION, "DivF", Type::NONE);
    IOperationInitializer *divFInitializer = new DivFInitializer();

    opcodeRegistry->registerOp(divFOp);
    operationFactory->registerOp(divFOp, divFInitializer);

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

    // StoreC Instruction
    Opcode storeCOp(OperationType::INSTRUCTION, "StoreC", Type::NONE);
    IOperationInitializer *storeCInitializer = new StoreCInitializer();

    opcodeRegistry->registerOp(storeCOp);
    operationFactory->registerOp(storeCOp, storeCInitializer);

    // StoreI Instruction
    Opcode storeIOp(OperationType::INSTRUCTION, "StoreI", Type::NONE);
    IOperationInitializer *storeIInitializer = new StoreIInitializer();

    opcodeRegistry->registerOp(storeIOp);
    operationFactory->registerOp(storeIOp, storeIInitializer);

    // StoreF Instruction
    Opcode storeFOp(OperationType::INSTRUCTION, "StoreF", Type::NONE);
    IOperationInitializer *storeFInitializer = new StoreFInitializer();

    opcodeRegistry->registerOp(storeFOp);
    operationFactory->registerOp(storeFOp, storeFInitializer);

    // LoadC Instruction
    Opcode loadCOp(OperationType::INSTRUCTION, "LoadC", Type::NONE);
    IOperationInitializer *loadCInitializer = new LoadCInitializer();

    opcodeRegistry->registerOp(loadCOp);
    operationFactory->registerOp(loadCOp, loadCInitializer);

    // LoadI Instruction
    Opcode loadIOp(OperationType::INSTRUCTION, "LoadI", Type::NONE);
    IOperationInitializer *loadIInitializer = new LoadIInitializer();

    opcodeRegistry->registerOp(loadIOp);
    operationFactory->registerOp(loadIOp, loadIInitializer);

    // LoadF Instruction
    Opcode loadFOp(OperationType::INSTRUCTION, "LoadF", Type::NONE);
    IOperationInitializer *loadFInitializer = new LoadFInitializer();

    opcodeRegistry->registerOp(loadFOp);
    operationFactory->registerOp(loadFOp, loadFInitializer);
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