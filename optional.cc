#include <iostream> 
#include <stdlib.h> 
#include <time.h>  
#include <optional>
#include <memory>
#include <map>
#include <vector>

using namespace std;  
struct Node {
    int val;
};

class PureVirtualClass {
public:
    PureVirtualClass(int i_) : i(i_) {}
    virtual void func(const Node& node) = 0;
    virtual ~PureVirtualClass() = default;
protected:
    int i = 0;;
};

class Body {
public:
    Body() {
        std::cout << "default construct" << std::endl;
    }
    Body(const Body& other) {
        std::cout << "copy construct" << std::endl;
    }
    Body(Body&& other) {
        std::cout << "move construct" << std::endl;
    }
    Body& operator=(const Body& other) {
        std::cout << "copy =" << std::endl;
    }
    std::unique_ptr<Node> up_n;
    std::map<int, std::vector<std::unique_ptr<Node> > > mp;
    std::vector<std::unique_ptr<Node> > vec;
    std::vector<int> i_vec;
    std::vector<std::unique_ptr<PureVirtualClass> > pure_virtual_class_vec;
    std::map<int, std::vector<std::unique_ptr<PureVirtualClass> > > pure_virtual_class_map; // clang could compile
};

int main() 
{  
    std::optional<Body> opt;
    opt = Body();
    opt->i_vec.emplace_back(1);
    
    std::cout << "after emplace_back with ->(pointer), opt i_vec.size " << opt->i_vec.size() << std::endl;
    opt.value().i_vec.emplace_back(2);
    std::cout << "value type " << typeid(opt.value()).name() << std::endl;
    std::cout << "after emplace_back with value func, opt i_vec.size " << opt->i_vec.size() << std::endl;
}
