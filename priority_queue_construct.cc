#include <iostream> 
#include <stdlib.h> 
#include <time.h>  
#include <map>
#include <queue>

using namespace std;  
class Node {
public:
    Node() = default;
    Node(int value) : val(value) {}
    Node& operator=(const Node& node) {
        val = node.val;
        return *this;
    }
    bool operator<(const Node& other) {
        return val < other.val;
    }
    bool operator>(const Node& other) {
        return val > other.val;
    }
    friend bool operator<(const std::shared_ptr<Node>& a, const std::shared_ptr<Node>& b) {
        return *a < *b;
    }
    friend bool operator>(const std::shared_ptr<Node>& a, const std::shared_ptr<Node>& b) {
        return *a > *b;
    }

    int val = 0;
};

static auto cmp = [](const std::shared_ptr<Node>& a, const std::shared_ptr<Node>& b) {
    return true;
};
struct InstanceJobsInfo {
    std::optional<std::shared_ptr<Node>> running_job;
    std::priority_queue<std::shared_ptr<Node>,
                        std::vector<std::shared_ptr<Node>>,
                        decltype(cmp)> waiting_jobs{cmp};
};


int main() 
{  
    //std::priority_queue<std::shared_ptr<Node>, std::deque<std::shared_ptr<Node>>, std::greater<std::shared_ptr<Node>>> q;
    std::priority_queue<std::shared_ptr<Node>> q;
    std::shared_ptr<Node> a(new Node(0));
    std::shared_ptr<Node> b(new Node(1));
    std::shared_ptr<Node> c(new Node(2));
    std::shared_ptr<Node> d(new Node(3));
    q.push(a);
    q.push(b);
    q.push(c);
    q.push(d);

    std::cout << "show queue: ";
    while (!q.empty()) {
        auto tmp = q.top();
        std::cout << " " << tmp->val;
        q.pop();
    }
    std::cout << std::endl;
}
