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
void show_shp_address(const std::shared_ptr<Node>& shp) {
    printf("%p\n", &shp);
}

void test_use_count1() {
    std::cout << "test_use_count1" << std::endl;
    int* int_p = new int(1);
    auto a = std::shared_ptr<int>(int_p);
    std::cout << "a.use_count " << a.use_count() << std::endl;
    auto b = a;
    std::cout << "a.use_count " << a.use_count()
            << ", b.use_count " << b.use_count() << std::endl;
    const auto& c = b;
    std::cout << "a.use_count " << a.use_count()
            << ", b.use_count " << b.use_count()
            << ", c.use_count " << c.use_count() << std::endl;

}

void test_use_count2() {
    std::cout << "test_use_count2" << std::endl;
    int* int_p = new int(1);
    auto a = std::shared_ptr<int>(int_p);
    std::cout << "a.use_count " << a.use_count() << std::endl;
    auto b = std::shared_ptr<int>(int_p);
    std::cout << "a.use_count " << a.use_count()
            << ", b.use_count " << b.use_count() << std::endl;
    const auto& c = b;
    std::cout << "a.use_count " << a.use_count()
            << ", b.use_count " << b.use_count()
            << ", c.use_count " << c.use_count() << std::endl;
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


    printf("%p\n", &node);
    show_shp_address(node);
    
    test_use_count1();
    test_use_count2();
    return 0;
}
