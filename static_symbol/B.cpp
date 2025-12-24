// B.cpp
#include "B.h"
#include <iostream>

void B::virt_func_for_vtable() {
    std::cout << "B virt_func_for_vtable" << std::endl;
}

int B::reg = [] {
    std::cout << "B registering..." << std::endl;
    Registry::instance().add("B");
    return 0;
}();

