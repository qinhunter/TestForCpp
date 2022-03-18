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

void test_function_sign(const std::shared_ptr<Node>& shp) {
    shp->add();
}

int main()
{
    // std::shared_ptr<std::string> shp = std::shared_ptr<std::string>(nullptr);
    // std::cout << "done" << std::endl;
    std::shared_ptr<std::string> a;
    auto b = a;
    std::cout << a.use_count() << std::endl;
    std::cout << b.use_count() << std::endl;
    std::cout << std::to_string(a == nullptr) << std::endl;
    if (a) {
        std::cout << "if a" << std::endl;
    } else {
        std::cout << "not if a" << std::endl;
    }
    Node n;
    if (n) {
        std::cout << "if n" << std::endl;
    } else {
        std::cout << "not if n" << std::endl;
    }
    Node n1(1);
    if (n1) {
        std::cout << "if n1" << std::endl;
    } else {
        std::cout << "not if n1" << std::endl;
    }

    auto node = std::make_shared<Node>(0);
    std::cout << "before add n " << node->val << std::endl;
    test_function_sign(node);
    std::cout << "after add n " << node->val << std::endl;
    return 0;
}
