// B.h
#include "A.h"
#include <iostream>

class B {
public:
    B() = default;
    virtual ~B() = default;
    virtual void virt_func_for_vtable();
    static int reg;
    void show() {
        std::cout<< "B show" << std::endl;
    }
};

