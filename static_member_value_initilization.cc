#include <iostream>

class A {
public:
    A() {
        std::cout << "A initialized" << std::endl;
    }
    static int x;
    int y = 0;
};

int A::x = [] {
    std::cout << "A::x initialized" << std::endl;
    return 42;
}();

int main() {
    std::cout << "main start\n";
    A a;
    return 0;
}

