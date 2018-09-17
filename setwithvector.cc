#include <iostream> 
#include <vector>
#include <string>
#include <set>



using namespace std;  

int main(int argc, char* argv[]) {
	set< vector<int> > seta;
	vector< set<int> > veca;
	cout << "seta and veca is built" << endl;
	
	int n = 5;
	vector<int> tmpvec;
	set<int> tmpset;
	
	// set could not be initialized with constructor set<type> seta(5, type);
	// because set holds no duplicate objects
	set< vector<int> > setb;
	setb.insert(tmpvec);	
	cout << "setb.size = " << setb.size() << endl;
	tmpvec.push_back(1);
	setb.insert(tmpvec);	
	cout << "setb.size = " << setb.size() << endl;
	vector<int> vecc;
	vecc.push_back(1);
	setb.insert(vecc);
	cout << "setb.size = " << setb.size() << endl;

	vector< set<int> > vecb(5, set<int>());
	cout << "vecb.size = " << vecb.size() << endl;

	return 0; 
}
