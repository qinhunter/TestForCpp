#include <iostream> 
#include <stdlib.h> 
#include <time.h>  
#include <map>
#include <queue>

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
    auto great_cmp = [](auto* a, auto* b) {
        return a->val > b->val;
    };
    auto less_cmp = [](auto* a, auto* b) {
        return a->val < b->val;
    };
    std::priority_queue<Node*, std::vector<Node*>, decltype(less_cmp)> q(less_cmp);
    std::cout << "q.size(): " << q.size() << ", q.empty(): " << q.empty() << std::endl;
    Node* a = new Node(-100);
    q.push(a);
    std::cout << "after push a into q, q.size(): " << q.size() << ", q.empty(): " << q.empty() << std::endl;
    auto* p_a = q.top();
    std::cout << "top of q: " << p_a->val << std::endl;
    auto* b = new Node(1);
    q.push(b);
    std::cout << "after push b into q, q.size(): " << q.size() << ", q.empty(): " << q.empty() << std::endl;
    std::cout << "top of q: " << q.top()->val << std::endl;
    auto* c = new Node(2);
    q.push(c);
    std::cout << "after push c into q, q.size(): " << q.size() << ", q.empty(): " << q.empty() << std::endl;
    std::cout << "top of q: " << q.top()->val << std::endl;
    q.pop();
    std::cout << "after pop q, q.size(): " << q.size() << ", q.empty(): " << q.empty() << std::endl;
}
