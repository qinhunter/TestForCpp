#include <memory>
#include <iostream> 
#include <stdlib.h> 
#include <time.h>  

using namespace std;  
int main() 
{  
    std::shared_ptr<std::string> shp = std::shared_ptr<std::string>(nullptr);
    std::cout << "done" << std::endl;
    return 0; 
}
