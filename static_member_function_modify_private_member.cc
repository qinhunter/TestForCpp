#include <iostream> 
#include <stdlib.h> 
#include <time.h>  

using namespace std;  
class Test{
    public:
        Test() = default;
        ~Test() = default;
        static void modify_private_member(Test* test) {
            Test new_test;
            // private member could be modified by static member function
            new_test.a = 1;
            std::cout << "new_test.a: " << new_test.a << std::endl;
            test->a = 2;
            std::cout << "test->a: " << test->a << std::endl;
        }
    private:
        int a;
};
int main() 
{  
    Test test;
    // private member could not be used by outside
    // test.a = 2;
    Test::modify_private_member(&test);
}
