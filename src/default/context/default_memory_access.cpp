#include "default_memory_access.hpp"

DefaultMemoryAccess::DefaultMemoryAccess(std::vector<unsigned char> *memory) {
    this->memory = memory;
}

char DefaultMemoryAccess::readChar(uint32_t location) {
    char data = 0;
    
    unsigned char *dp = reinterpret_cast<unsigned char *>(&data);
    read(location, sizeof(char), dp);

    return data;
}

int DefaultMemoryAccess::readInt(uint32_t location) {
    int data = 0;
    
    unsigned char *dp = reinterpret_cast<unsigned char *>(&data);
    read(location, sizeof(int), dp);
    
    return data;
}

float DefaultMemoryAccess::readFloat(uint32_t location) {
    float data = 0;
    
    unsigned char *dp = reinterpret_cast<unsigned char *>(&data);
    read(location, sizeof(float), dp);
    
    return data;
}

double DefaultMemoryAccess::readDouble(uint32_t location) {
    double data = 0;
    
    unsigned char *dp = reinterpret_cast<unsigned char *>(&data);
    read(location, sizeof(double), dp);

    return data;
}

uint32_t DefaultMemoryAccess::readAddress(uint32_t location) {
    uint32_t data = 0;
    
    unsigned char *dp = reinterpret_cast<unsigned char *>(&data);
    read(location, sizeof(uint32_t), dp);
    
    return data;
}

void DefaultMemoryAccess::read(uint32_t location, uint32_t size, unsigned char* dp) {
    for(uint32_t i = 0; i < size; i++) {
        dp[i] = memory->at(location + i);
    }
}

void DefaultMemoryAccess::writeChar(uint32_t location, char data) {
    write(location, sizeof(char), reinterpret_cast<unsigned char const*>(&data));
}

void DefaultMemoryAccess::writeInt(uint32_t location, int data) {
    write(location, sizeof(int), reinterpret_cast<unsigned char const*>(&data));
}

void DefaultMemoryAccess::writeFloat(uint32_t location, float data) {
    write(location, sizeof(float), reinterpret_cast<unsigned char const*>(&data));
}

void DefaultMemoryAccess::writeDouble(uint32_t location, double data) {
    write(location, sizeof(double), reinterpret_cast<unsigned char const*>(&data));
}

void DefaultMemoryAccess::writeAddress(uint32_t location, uint32_t data) {
    write(location, sizeof(uint32_t), reinterpret_cast<unsigned char const*>(&data));
}

void DefaultMemoryAccess::write(uint32_t location, uint32_t size, unsigned char const* data) {
    for(uint32_t i = 0; i != size; i++) {
        memory->at(location + i) = data[i];
    }
}

uint32_t DefaultMemoryAccess::size() {
    return memory->size();
}