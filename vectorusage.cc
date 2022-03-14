#include <iostream> 
#include <vector>
#include <string>

using namespace std;  

void helper(const std::vector<int>& a) {
    std::cout << "a.size: " << a.size() << std::endl;
    auto it = a.begin();
    std::cout << "a.begin: " << *it << std::endl;
    std::cout << "a.begin + 3: " << *(it + 3) << std::endl;
    std::vector<std::pair<const std::vector<int>&, int>> stack;
}

void show_rit(const std::vector<int>& vec) {
    std::cout << "show rit:";
    for (auto rit = vec.rbegin(); rit != vec.rend(); ++rit) {
        std::cout << " " << *rit;
    }
    std::cout << std::endl;
}

void show_rit_base(const std::vector<int>& vec) {
    std::cout << "show rit_base:";
    for (auto rit = vec.rbegin(); rit != vec.rend(); ++rit) {
        std::cout << " " << *rit.base();
    }
    std::cout << std::endl;
}
void pop_empty_vec() {
    std::vector<std::string> vec;
    // vec.pop_back();
    std::cout << "pop empty vec will core!!!" << std::endl;
}

int main(int argc, char* argv[]) {
	vector<int> a;
	a.push_back(1);
	cout << "a.size = " << a.size() << endl;
	a[0] = 2;
	a[1] = 3;// this doesn't work and it is dangerous!
    // actually it's OK, because vector allocate mem to store data and the mem size is capacity. If size is not bigger than capacity, a[1] = 3 is OK.
	cout << "a.size = " << a.size() << endl;

    std::vector<int> b = {0, 1, 2, 3, 4, 5, 6, 7};
    helper(b);

    show_rit(b);
    show_rit_base(b);
    pop_empty_vec();


	return 0; 
}
