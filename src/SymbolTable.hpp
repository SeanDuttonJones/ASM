#ifndef ASM_SYMBOL_TABLE_CLASS_H
#define ASM_SYMBOL_TABLE_CLASS_H

#include <map>

class SymbolTable {
    private:
        std::map<std::string, int64_t> table;

    public:
        void insert(std::string key, int64_t value);
        int64_t get(std::string key);
        std::string toString();
};

#endif