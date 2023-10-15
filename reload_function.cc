#include <memory>
#include <iostream> 
#include <stdlib.h> 
#include <time.h>  

using namespace std;  

struct Node {
    Node(const int& __val = 0) : val(__val) {}
    operator bool() {
        return val != 0;
    }
    void add() {
        ++val;
    }
    void show() {
        std::cout << "normal show val " << val << std::endl;
    }
    void show() const {
        std::cout << "const show val " << val << std::endl;
    }
    int val = 0;
};


int main()
{
    Node a;
    a.show();
    const Node b;
    b.show();
}
