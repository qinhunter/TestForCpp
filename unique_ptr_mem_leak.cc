#include <memory>
#include <iostream> 
#include <stdlib.h> 
#include <time.h>  
#include <unordered_map>

using namespace std;  

struct Base {
    virtual std::unique_ptr<Base> copy() = 0;
    ~Base() {
        std::cout << "Base desctruct" << std::endl;
    }
};

struct Derive : public Base {
    std::unique_ptr<Base> copy() override {
        auto tmp = std::make_unique<Derive>(*this);
        for (int i = 0; i < 1000; ++i) {
            tmp->val.push_back(i);
        }
        return tmp;
    }
    ~Derive() {
        std::cout << "Derive desctruct" << std::endl;
    }

    std::string val;
};

struct All {
    All() = default;
    All(const All& other) {
        for (const auto& [k, v] : other.m) {
            this->m.emplace(k, v->copy());
        }
    }
    std::unordered_map<std::string, std::unique_ptr<Base>> m;
};


void test(const All& a) {
    static int i = 0;
    All b(a);

    if (i % 1000000 == 0) {
        std::cout << "i " << i << ", b.m size " << b.m.size() << std::endl;
    }
    ++i;
}

int main()
{
    // std::shared_ptr<std::string> shp = std::shared_ptr<std::string>(nullptr);
    // std::cout << "done" << std::endl;
    // auto a = std::make_unique<std::string>("test");
    // std::cout << "a " << *a << std::endl;
    All a;
    a.m.emplace("1", std::make_unique<Derive>());
    for (int64_t turn = 0; turn <= 100000000; ++turn) {
        std::cout << "turn  " << turn << std::endl;
        test(a);
        // if (i % 1000000 == 0) {
        //     std::cout << "i " << i << std::endl;
        //     test(a);
        // }
    }
    return 0;
}
