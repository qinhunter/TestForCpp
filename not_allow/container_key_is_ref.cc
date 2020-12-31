#include <iostream> 
#include <vector>
#include <string>
#include <set>
#include <map>
#include <unordered_set>

/* container's key could not be set as const type&
 */
using namespace std;  

int main(int argc, char* argv[]) {
    std::unordered_set<std::string> set1;
    std::unordered_set<std::string> set2;
    set1.insert("str1");
    set1.insert("str2");
    set2.insert("str2");
    set2.insert("str3");

    std::unordered_set<std::string> string_set;
    for (const auto& s : set1) {
        string_set.insert(s);
    }
    for (const auto& s : set2) {
        string_set.insert(s);
    }
    std::cout << "show string_set" << std::endl;
    for (const auto& s : string_set) {
        std::cout << s << std::endl;
    }

    std::map<const std::string&, std::string> ref_set;
    // std::unordered_set<const std::string&> ref_set;

	return 0; 
}
