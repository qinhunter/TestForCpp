// main.cpp
#include "A.h"
#include "B.h"

void register_func() {
    std::unique_ptr<B> b(new B());
    // b->show();
}
int main() {
    Registry::instance().dump();
    register_func();
    return 0;
}

