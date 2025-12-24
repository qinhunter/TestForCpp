// main.cpp
#include "A.h"
#include "B.h"

void register_func() {
    std::unique_ptr<B> b(new B()); // only when b realizes virtual function, this way works.
    // b->show(); // if b does not realize virtual function, explicitly using B's function also runs and may be the only way.
}
int main() {
    Registry::instance().dump();
    register_func();
    return 0;
}

