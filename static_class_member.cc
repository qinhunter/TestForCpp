#include <iostream> 
#include <stdlib.h> 
#include <time.h>  
#include "static_class_member.h"


using namespace std;  
std::string Test::static_str;
int main() 
{  
    std::cout << "show static_str" << Test::get_static_str() << std::endl;
    // private member could not be used by outside
    // test.a = 2;
}
