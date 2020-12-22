#include <iostream> 
#include <stdlib.h> 
#include <time.h>  
#include<map>

using namespace std;  
int main() 
{  
    std::map<int, std::pair<int, int>> a;
    int& b = a[1].first = 2;
    std::cout << 1;
    return 0;
}
