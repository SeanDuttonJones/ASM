#include <iostream>
#include "Asm.hpp"
#include "AsmLoader.hpp"
#include <charconv>

using namespace std;

int main() {
    Asm stackMachine;
    AsmLoader loader(stackMachine);
    cout << "LOADING..." << endl;
    loader.load("./input/test.asm");
};