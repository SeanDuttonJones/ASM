#ifndef ABS_MEMORY_ACCESS_CLASS
#define ABS_MEMORY_ACCESS_CLASS

#include <array>

class IMemoryAccess {
    public:
        virtual char readChar(uint32_t location) = 0;
        virtual int readInt(uint32_t location) = 0;
        virtual float readFloat(uint32_t location) = 0;
        virtual double readDouble(uint32_t location) = 0;
        virtual unsigned char* read(uint32_t location, uint32_t size) = 0;

        virtual void writeChar(uint32_t location, char data) = 0;
        virtual void writeInt(uint32_t location, int data) = 0;
        virtual void writeFloat(uint32_t location, float data) = 0;
        virtual void writeDouble(uint32_t location, double data) = 0;
        virtual void write(uint32_t location, unsigned char* data) = 0;

        virtual uint32_t size() = 0;
};

#endif