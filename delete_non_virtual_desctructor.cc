#include <memory>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <unordered_map>

// g++ -std=c++17 -o delete_non_virtual_dtor.o delete_non_virtual_dtor.cc -Werror=delete-non-virtual-dtor

using namespace std;

struct SimpleStruct {
    ~SimpleStruct() {
        std::cout << "SimpleStruct destruct" << std::endl;
    }
};

struct Base {
    // virtual void test() = 0;
    virtual void test() {
        std::cout << "Base test" << std::endl;
    }
    ~Base() {
    // virtual ~Base() {
        std::cout << "Base desctruct" << std::endl;
    }
    // std::string val;
    char c0;
    char c1;
    char c2;
    char c3;
    char c4;
    char c5;
    char c6;
    char c7;
    // char c8;
};

struct Derive : public Base {
    virtual void test() {
        std::cout << "Derive test" << std::endl;
    }
    // ~Derive() {
    //     std::cout << "Derive desctruct" << std::endl;
    // }
    SimpleStruct simple;

};


struct EmptyStruct {

};

int main()
{
    Base b;
    Derive d;
    EmptyStruct e;
    std::cout << "sizeof Base " << sizeof(b) << std::endl;
    std::cout << "sizeof Derive " << sizeof(d) << std::endl;
    std::cout << "sizeof EmptyStruct " << sizeof(e) << std::endl;
    Base* a = new Derive();
    a->test();
    delete a;
    std::cout << "after delete a" << std::endl;
    return 0;
}
