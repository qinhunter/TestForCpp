#include<stdio.h>
#include <iostream>

class A {
public:
    A(int _a = 0) : a(_a) {
        std::cout << "construct A " << a << std::endl;
    }
    ~A() {
        std::cout << "destruct A " << a << std::endl;
    }
	int a;
	int b;
};

int main() {
    A a(1);
    A(2);
    std::cout << "test" << std::endl;
	return 0;
}
