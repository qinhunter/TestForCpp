#include <iostream> 
#include <vector>
#include <string>

class Testclass {
public:
	Testclass(int num = 0) : _num(num) {
		std::cout << this << " constructor " << std::to_string(_num) << std::endl;
	}

	Testclass(const Testclass& other) : _num(other._num) {
		std::cout << this << " copy constructor " << std::to_string(_num) << std::endl;
	}

	Testclass(Testclass&& other) : _num(other._num) {
		std::cout << this << " move copy constructor " << std::to_string(_num) << std::endl;
        other._num = -other._num;
	}

	~Testclass() {
		std::cout << this << " destructor " << std::to_string(_num) << std::endl;
	}
	int _num;

};

Testclass make_test_class(int num = 0) {
    Testclass tmp(num);
    return tmp;
}

int main(int argc, char* argv[]) {
    Testclass t1(1);
    Testclass t2 = std::move(t1);
    Testclass t3 = make_test_class(3);
    Testclass&& t4 = make_test_class(4);
    Testclass t5 = std::move(make_test_class(5));
    std::cout << std::to_string(make_test_class(6)._num) << std::endl;
    std::cout << "finish all tests, begin to exit" << std::endl;
	return 0; 
}
