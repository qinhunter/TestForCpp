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

Testclass make_test_class_and_do_something(int num = 0) {
    Testclass tmp(num);
    std::cout << &tmp << " after construct " << std::to_string(tmp._num) << std::endl;
    return tmp;
}

Testclass make_test_class_random(int num = 0) {
    Testclass tmp1(num);
    Testclass tmp2(num);
    int i = num % 2;
    return i == 0 ? tmp1 : tmp2;
}

Testclass make_test_class_random2(int num = 0) {
    int i = num % 2;
    return i == 0 ? Testclass(num + 1) : Testclass(num + 2);
}

int main(int argc, char* argv[]) {
    Testclass t1(1);
    Testclass t2 = std::move(t1);
    Testclass t3 = make_test_class(3);
    Testclass&& t4 = make_test_class(4);
    Testclass t5 = std::move(make_test_class(5));
    std::cout << std::to_string(make_test_class(6)._num) << std::endl;
    Testclass t7 = make_test_class_and_do_something(7);
    Testclass t8 = make_test_class_random(8);
    Testclass&& t9 = make_test_class_random(9);
    Testclass t10 = std::move(make_test_class_random(10));
    Testclass t11 = make_test_class_random2(11);
    std::cout << "finish all tests, begin to exit" << std::endl;
	return 0; 
}
