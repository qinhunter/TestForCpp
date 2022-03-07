#include <iostream> 
#include <stdlib.h> 
#include <time.h>  
#include <stdio.h>

#include <stdarg.h>





int main() 
{  
    auto t = static_cast<uint32_t>(std::time(nullptr));
    std::cout << "std::time: " << std::time(nullptr) << std::endl;

    time_t tt;
    time(&tt);
    std::cout << "time_t: " << tt << std::endl;

    std::time_t curr_time = std::time(nullptr);
    std::tm* p_tm = std::gmtime(&curr_time);
    std::time_t gtime = mktime(p_tm);
    std::cout << "gmtime/mktime: " << gtime << std::endl;
    // printf("%u\n", t);
	return 0; 
}
