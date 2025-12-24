// A.cpp
#include "A.h"
#include <iostream>

Registry& Registry::instance() {
    static Registry inst;
    return inst;
}

void Registry::add(const std::string& name) {
    items.push_back(name);
}

void Registry::dump() const {
    std::cout << "Registered items:" << std::endl;
    for (auto& s : items) {
        std::cout << "  " << s << std::endl;
    }
}

