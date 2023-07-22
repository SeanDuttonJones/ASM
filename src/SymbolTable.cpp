#include "SymbolTable.hpp"

void SymbolTable::insert(std::string key, int64_t value) {
    table.insert({key, value});
}

int64_t SymbolTable::get(std::string key) {
    std::map<std::string, int64_t>::iterator it = table.find(key);
    if(it != table.end()) {
        return it->second;
    }

    return -1;
}

std::string SymbolTable::toString() {
    std::string s = "{ ";
    for(std::map<std::string, int64_t>::iterator it = table.begin(); it != table.end(); it++) {
        s += it->first + ": " + std::to_string(it->second) + ", ";
    }

    // removes last ", "
    if(s.size() > 2) {
        s.pop_back();
        s.pop_back();
    }

    s += " }";

    return s;
}