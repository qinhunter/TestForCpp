#include <iostream> 
#include <stdlib.h> 
#include <time.h>  
#include <map>
#include <unordered_map>

using namespace std;  
int main() 
{  
    std::map<int, double> c1{{1, 1.0}, {2, 2.0}};
    std::map<int, double> c2{{1, 1.0}, {2, 2.0}};
    std::map<int, double> c3{{2, 2.0}, {3, 2.0}};
    std::map<int, double> c4{{2, 2.0}, {3, 3.0}};

    std::cout << std::boolalpha;
    std::cout << "c1 == c2 " << (c1 == c2) << std::endl;
    std::cout << "c1 < c3 " << (c1 < c3) << std::endl;
    std::cout << "c1 < c4 " << (c1 < c4) << std::endl;
    std::cout << "c3 < c4 " << (c3 < c4) << std::endl;
}
