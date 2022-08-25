#include <iostream> 
#include <stdlib.h> 
#include <time.h>  
#include <optional>
#include <memory>
#include <map>
#include <vector>

using namespace std;  
struct Node {
    Node(int a, int b) : val1(a), val2(b) {}
    int val1;
    int val2;
    bool operator==(const Node& other) {
        printf("compare %d and %d\n", this, &other);
        return this->val1 == other.val1 && this->val2 == other.val2;
    }
    friend bool operator==(const Node& a, const Node& b) {
        printf("friend compare %d and %d\n", &a, &b);
        return a.val1 == b.val1 && a.val2 == b.val2;
    }
    // bool operator!=(const Node& other) {
    //     printf("unequal compare %d and %d\n", this, &other);
    //     return !(*this == other);
    // }
    friend bool operator!=(const Node& a, const Node& b) {
        printf("friend unequal compare %d and %d\n", &a, &b);
        return !(a == b);
    }
};


int main() 
{  
    Node a(1, 2);
    Node b(2, 3);
    std::vector<Node> vec1;
    vec1.emplace_back(1, 2);
    std::vector<Node> vec2;
    vec2.emplace_back(2, 3);
    // printf("a == b %d\n", a == b);
    printf("vec1 == vec2 %d\n", vec1 == vec2);
    // printf("a != b %d\n", a != b);
    // printf("vec1 != vec2 %d\n", vec1 != vec2);
}
