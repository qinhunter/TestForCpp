#include <iostream> 
#include <vector>
#include <string>



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
	vector<string> s1;
	int vector_size = 0;
	for(int i = 0;i < vector_size;i++) {
		s1.push_back("Hunter" + to_string(i));
	}
	string tmp;
	for(int i = 0;i < vector_size;i++) {
		cout << "i = " << i << ", before move s1 size = " << s1.size() << endl;
		tmp = std::move(s1[i]);
		cout << "after move s1 size = " << s1.size() << ", tmp = " << tmp << endl;
	}

	for(int i = 0;i < vector_size;i++) {
		cout << "s1[" << i << "] = \"" << s1[i] << "\""<< endl;
	}

	vector<Testclass> testclass_vec;
	testclass_vec.reserve(10);// Without reserving, push_back will resize the vector for many times, which will influence the efficiency and the most important is that it will construct or destruct element in the vector.
	Testclass testclass(5);
	cout << "after build" << endl;
	testclass_vec.push_back(std::move(testclass));
	cout << "after push back testclass" << endl;
	testclass_vec.push_back(Testclass(3));
	cout << "after push back tmp object" << endl;
	return 0; 
}
