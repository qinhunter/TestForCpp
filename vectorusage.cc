#include <iostream> 
#include <vector>
#include <string>



using namespace std;  

int main(int argc, char* argv[]) {
	vector<int> a;
	a.push_back(1);
	cout << "a.size = " << a.size() << endl;
	a[0] = 2;
	a[1] = 3;// this doesn't work and I do not know if it is dangerous!
	cout << "a.size = " << a.size() << endl;
	return 0; 
}
