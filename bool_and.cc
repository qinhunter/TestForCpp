#include <iostream> 
#include <stdlib.h> 
#include <time.h>  

using namespace std;  
bool get_true() {
    std::cout << "get true" << std::endl;
    return true;
}

bool get_false() {
    std::cout << "get false" << std::endl;
    return false;
}

int main() 
{  
    bool truea = true;
    bool trueb = true;
    bool falsea = false;
    bool falseb = false;
    std::cout << "truea " << truea << std::endl;
    std::cout << "trueb " << trueb << std::endl;
    std::cout << "falsea " << falsea << std::endl;
    std::cout << "falseb " << falseb << std::endl;
    truea &= get_true();
    std::cout << "truea after &= true " << truea << std::endl;
    trueb &= get_false();
    std::cout << "trueb after &= false " << trueb << std::endl;
    falsea &= get_true();
    std::cout << "falsea after &= true " << falsea << std::endl;
    falseb &= get_false();
    std::cout << "falseb after &= false " << falseb << std::endl;
    return 0; 
}

