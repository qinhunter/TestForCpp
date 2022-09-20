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
    int val = 0;
};

int main()
{
    // std::shared_ptr<std::string> shp = std::shared_ptr<std::string>(nullptr);
    // std::cout << "done" << std::endl;
    // auto a = std::make_unique<std::string>("test");
    // std::cout << "a " << *a << std::endl;
    std::unique_ptr<std::string> a = std::make_unique<std::string>();
    auto b = a;
    return 0;
}
