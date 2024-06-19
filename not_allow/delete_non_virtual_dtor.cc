#include <memory>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <unordered_map>

// g++ -std=c++17 -o unique_ptr_mem_leak.o unique_ptr_mem_leak.cc -Werror=delete-non-virtual-dtor

using namespace std;

struct Base {
    virtual void test() = 0;
    ~Base() {
        std::cout << "Base desctruct" << std::endl;
    }
};

struct Derive : public Base {
    virtual void test() {
        std::cout << "Dervice test" << std::endl;
    }
    ~Derive() {
        std::cout << "Derive desctruct" << std::endl;
    }

    std::string val;
};

int main()
{
    Base* a = new Derive();
    a->test();
    delete a;
    return 0;
}
