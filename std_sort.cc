#include <iostream> 
#include <vector>
#include <string>
#include <set>
#include <map>
#include <unordered_set>

/* 
 * test std::sort vectors with vector inside
 */
using namespace std;  

int main(int argc, char* argv[]) {
    std::vector<std::vector<int>> segments;
    segments.push_back({2, 3});
    segments.push_back({1, 3});
    segments.push_back({1, 4});
    segments.push_back({1, 2});
    segments.push_back({1, 6});
    segments.push_back({1, 7});
    segments.push_back({2, 7});
    segments.push_back({2, 2});
    segments.push_back({2, 1, 3});
    std::cout << "before sort:";
    for (const auto& segment : segments) {
        std::cout << " [" << segment[0] << ", " << segment[1] << "]";
    }
    std::cout << std::endl;
    std::cout << "after sort:";
    
    std::sort(segments.begin(), segments.end());
    for (const auto& segment : segments) {
        std::cout << " [" << segment[0] << ", " << segment[1] << "]";
    }
    std::cout << std::endl;
	return 0; 
}
