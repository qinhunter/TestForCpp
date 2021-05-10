#include <iostream> 
#include <stdlib.h> 
#include <time.h>  
#include<map>

using namespace std;  
class Node {
public:
    Node() : val(-1) {
        std::cout << "default constructor val: " << val << std::endl;
    }
    Node(int value) : val(value) {
        std::cout << "constructor val: " << val << std::endl;
    }
    Node(const Node& node) {
        val = node.val + 1;
        std::cout << "copy constructor val: " << val << std::endl;
    }
    Node& operator=(const Node& node) {
        val = node.val + 2;
        std::cout << "opeartor= val: " << val << std::endl;
        return *this;
    }
    int val = 0;
};
int main() 
{  
    std::map<int, Node> a;
    Node node(1);
    a[1] = node;
    Node new_node(a[1]);
    return 0;
}
