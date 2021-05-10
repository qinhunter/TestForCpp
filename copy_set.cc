#include <iostream> 
#include <vector>
#include <string>
#include <set>



using namespace std;  

int main(int argc, char* argv[]) {
    std::set<std::string> seta;
    std::set<std::string> setb;
    seta.insert(setb.begin(), setb.end());
    if (setb.begin() == setb.end()) {
        std::cout << "begin == end" << std::endl;
    }
}
