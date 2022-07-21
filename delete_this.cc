#include <iostream> 
#include <stdlib.h> 
#include <time.h>  

using namespace std;  

struct A {
    void test_delete_this() {
        std::cout << "delete " << this << std::endl;
        delete this;
        // this = nullptr; illegal expression
        std::cout << "finish delete " << this << std::endl;
    }
};

int main() 
{  
    auto* a = new A;
    a->test_delete_this();
    A b;
    std::cout << "try to execute delete_this with struct on stack, which will core" << std::endl;
    b.test_delete_this();
    return 0; 
}

