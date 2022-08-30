#include <iostream> 
#include <stdlib.h> 
#include <time.h>  
#include <map>
#include <unordered_map>

using namespace std;  
int main() 
{  
    std::unordered_map<std::string, int> test_map;
    test_map["a"] = 10;
    test_map["b"] = 5;
    test_map["c"] = 2;
    test_map["d"] = 9;
    test_map["e"] = 6;
    auto res = std::min_element(test_map.begin(), test_map.end(),
                                // left and right is pair
                                // the realization in min_element is cmp(*it1, *it2)
                               [] (const auto& left, const auto& right) {
                                    return left.second < right.second;
                               })->second;
    printf("res %d\n", res);
    return 0;
}
