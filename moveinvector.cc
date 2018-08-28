#include <iostream> 
#include <vector>
#include <string>



using namespace std;  

int main(int argc, char* argv[]) {
	vector<string> s1;
	for(int i = 0;i < 10;i++) {
		s1.push_back("Hunter" + to_string(i));
	}
	string tmp;
	for(int i = 0;i < 10;i++) {
		cout << "i = " << i << ", before move s1 size = " << s1.size() << endl;
		tmp = std::move(s1[i]);
		cout << "after move s1 size = " << s1.size() << ", tmp = " << tmp << endl;
	}

	for(int i = 0;i < 10;i++) {
		cout << "s1[" << i << "] = \"" << s1[i] << "\""<< endl;
	}

	return 0; 
}
