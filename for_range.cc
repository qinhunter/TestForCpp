#include <iostream> 
#include <vector>
#include <string>
#include <map>
#include <unordered_map>



using namespace std;  

class Testclass {
public:
	Testclass(int num = 0) : _num(num) {
		cout << this << " constructor " << to_string(_num) << endl;
	}

	Testclass(const Testclass& other) : _num(other._num) {
		cout << this << " copy constructor " << to_string(_num) << endl;
	}

	Testclass(Testclass&& other) : _num(other._num) {
		cout << this << " move copy constructor " << to_string(_num) << endl;
	}

	~Testclass() {
		cout << this << " destructor " << to_string(_num) << endl;
	}
	int _num;

};

int main(int argc, char* argv[]) {
	vector<Testclass> testclass_vec;
	testclass_vec.reserve(10);// Without reserving, push_back will resize the vector for many times, which will influence the efficiency and the most important is that it will construct or destruct element in the vector.
    for (int i = 0; i < 10; ++i) {
	    testclass_vec.emplace_back(i);
    }
    std::cout << "show vector\n";
    for (const auto& tmp : testclass_vec) {
        std::cout << &tmp << ": " << to_string(tmp._num) << std::endl;
    }
    std::cout << "modify vector\n";
    for (auto&& tmp : testclass_vec) {
        tmp._num += 10;
        std::cout << &tmp << ": " << std::to_string(tmp._num) << std::endl;
    }
    std::unordered_map<int, Testclass*> testclass_map;
	return 0; 
}
