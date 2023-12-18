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
    auto vec_with_shptr = std::vector<std::shared_ptr<int>>(10, std::make_shared<int>(1));
    for (const auto& a : vec_with_shptr) {
        printf("%d \n", a.get());
    }
    auto vec_with_uniqptr = std::vector<std::unique_ptr<int>>(10, std::make_unique<int>(1));
    for (const auto& a : vec_with_uniqptr) {
        printf("%d \n", a.get());
    }
}
