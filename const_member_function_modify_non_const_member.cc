#include <iostream> 
#include <stdlib.h> 
#include <time.h>  

using namespace std;  
class Base {
public:
    void update(const int& v) {
        b = v;
    }
    int b = 0;
};

class Test{
    public:
        Test() {
            base = new Base();
        }
        ~Test() {
            delete base;
        }
        void show() const {
            std::cout << "a = " << a << ", base->b = " << base->b << std::endl;
        }
        void modify_member() const {
            std::cout << "start modify_member" << std::endl;
            show();
            base->b = 2;
            std::cout << "after set base->b" << std::endl;
            show();
            base->update(3);
            std::cout << "after call base->update" << std::endl;
            show();
        }
    private:
        int a = 0;
        Base* base = nullptr;
};
int main() 
{  
    Test test;
    test.modify_member();
}
