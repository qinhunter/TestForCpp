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

int main(int argc, char* argv[]) {
	vector<int> a;
	a.push_back(1);
	cout << "a.size = " << a.size() << endl;
	a[0] = 2;
	a[1] = 3;// this doesn't work and I do not know if it is dangerous!
    // actually its OK, because vector allocate mem to store data and the mem size is capacity. If size is not bigger than capacity, a[1] = 3 is OK.
	cout << "a.size = " << a.size() << endl;

    std::vector<int> b = {0, 1, 2, 3, 4, 5, 6, 7};
    helper(b);
	return 0; 
}
