#include <iostream>
#include <array>
#include "Asm.hpp"
#include "loader.hpp"
#include <charconv>

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

    Asm *stackMachine = new Asm();
    
    Loader loader(stackMachine);
    cout << "LOADING..." << endl;
    loader.load("./input/test.asm");
    cout << "LOADING COMPLETE!\n" << endl;
    
    cout << "STARTING STACK MACHINE..." << endl;
    stackMachine->start();
    cout << "STACK MACHINE FINISHED!" << endl;
    
    delete stackMachine;
};