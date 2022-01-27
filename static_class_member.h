#include <iostream> 
#include <stdlib.h> 
#include <time.h>  

using namespace std;  
class Test{
    public:
        Test() = default;
        ~Test() = default;
        // static int helper_init() {
        //     Test::static_str = "123456";
        //     return 0;
        // }
        static const std::string& get_static_str() {
            // static int helper_res = helper_init();
            return static_str;
        }
        const int get_a() {
            return a;
        }
    private:
        static std::string static_str;
        int a;
};
