#include <iostream> 
#include <stdlib.h> 
#include <time.h>  
#include <map>
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
    int val = 0;
};
int main() 
{  
    std::map<int, Node> a;
    Node node(1);
    a[1] = node;
    Node new_node(a[1]);
    // key could not be set as vector<int> !!!
    // std::unordered_map<std::vector<int>, std::vector<int>> vec_to_vec_map;
    std::unordered_map<int, int> map1;
    map1.reserve(1000);
    std::unordered_map<int, int> map2;
    map2.reserve(100);
    std::cout << "empty map1 equals empty map2: " << (map1 == map2) << std::endl;
    map1[1] = 2;
    std::cout << "inserted map1 equals map2: " << (map1 == map2) << std::endl;
    map2[1] = 2;
    std::cout << "map1 equals inserted map2: " << (map1 == map2) << std::endl;
    map1[2] = map2[2] = 3;
    map1[20000001] = map2[20000001] = 3;
    map1[200000001] = map2[200000001] = 3;
    map1[2000000001] = map2[2000000001] = 3;
    map1[100000000001] = map2[100000000001] = 3;
    std::cout << "map1 equals map2: " << (map1 == map2) << std::endl;
    return 0;
}
