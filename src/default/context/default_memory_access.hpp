#ifndef DEFAULT_MEMORY_ACCESS_CLASS
#define DEFAULT_MEMORY_ACCESS_CLASS

#include <vector>

#include "memory_access_interface.hpp"

class DefaultMemoryAccess : public IMemoryAccess {
    private:
        std::vector<unsigned char> *memory;

    public:
        DefaultMemoryAccess(std::vector<unsigned char> *memory);
        
        char readChar(uint32_t location);
        int readInt(uint32_t location);
        float readFloat(uint32_t location);
        double readDouble(uint32_t location);
        uint32_t readAddress(uint32_t location);
        void read(uint32_t location, uint32_t size, unsigned char* data);

        void writeChar(uint32_t location, char data);
        void writeInt(uint32_t location, int data);
        void writeFloat(uint32_t location, float data);
        void writeDouble(uint32_t location, double data);
        void writeAddress(uint32_t location, uint32_t data);
        void write(uint32_t location, uint32_t size, unsigned char const* data);
        uint32_t size();
};

#endif