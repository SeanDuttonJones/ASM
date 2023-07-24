#include "operation.hpp"

#include <iostream>

class PushIInstruction: public Operation {
    public:
        void execute() {
            std::cout << "PushI executing" << std::endl;
        }
};