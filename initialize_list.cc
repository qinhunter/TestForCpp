#include <iostream> 
#include <stdlib.h> 
#include <time.h>  
#include <vector>

using namespace std;  
int main() 
{  
    std::vector<std::pair<int, int>> list{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    for (const auto& [a, b] : std::vector<std::pair<int, int>>{{-1, 0}, {1, 0}, {0, -1}, {0, 1}}) {
        std::cout << "a " << a << ",\tb " << b << endl;
    }
}
