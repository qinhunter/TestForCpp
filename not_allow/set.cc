#include <iostream> 
#include <stdlib.h> 
#include <time.h>  
#include <map>
#include <set>
#include <unordered_map>

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
    bool operator<(const Node& other) {
        return this->val < other.val;
    }
    int val = 0;
};
int main() 
{  
    std::set<Node> s;
    s.emplace(1);
    s.emplace(2);
    s.emplace(3);
    s.emplace(4);
    for (const auto& c : s) {
        std::cout << c.val << std::endl;
    }
    for (auto& c : s) {
        if (c.val == 2) {
            c.val = 6;
        }
    }
    std::cout << "after changed" << std::endl;
    for (const auto& c : s) {
        std::cout << c.val << std::endl;
    }
    return 0;
}
