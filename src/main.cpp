#include <iostream>
#include "Asm.hpp"
#include "loader.hpp"
#include <charconv>

using namespace std;

int main() {
    Asm stackMachine;
    Loader loader(stackMachine);
    cout << "LOADING..." << endl;
    loader.load("./input/test.asm");
    stackMachine.run();
};