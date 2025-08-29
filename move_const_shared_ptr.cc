#include <memory>
#include <iostream> 
#include <stdlib.h> 
#include <time.h>  

using namespace std;  

struct Node {
    Node(const int& val_) : val(val_) {
        std::cout << "build Node with val " << val << std::endl;
    }
    Node(const Node& from) : val(from.val) {
        std::cout << "copy Node with val " << from.val << std::endl;
    }
    int val = 0;
};

int main()
{
    auto sp1 = std::make_shared<Node>(0);
    const auto& ref1 = sp1; 
    auto sp2 = std::move(ref1);
    std::cout << "sp2 is built from move const ref1, sp1.use_count" << sp1.use_count() << ", sp2.use_count " << sp2.use_count() << std::endl;
    sp2 = std::move(sp1);
    std::cout << "move sp1 to sp2, sp1.use_count" << sp1.use_count() << ", sp2.use_count " << sp2.use_count() << std::endl;
    return 0;
}
