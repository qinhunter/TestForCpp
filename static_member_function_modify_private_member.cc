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
        void modify_static_member() {
            static int stat_int = 0;
            std::cout << " stat_int is " << stat_int << std::endl;
            ++stat_int;
            std::cout << "after modify stat_int is " << stat_int << std::endl;
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
    Test test1;
    Test test2;
    test1.modify_static_member();
    test2.modify_static_member();
}
