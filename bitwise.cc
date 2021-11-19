#include <iostream> 
#include <stdlib.h> 
#include <time.h>  

using namespace std;  
int hammingDistance(int x, int y) {
    int t = x ^ y;
	int ans = 0;
	for (int i = 0; i < 32; ++i) {
		int flag = 1 << i;
		if ((flag & t) > 0) {
			++ans;
		}
	}
	return ans;
}

int main() 
{  
    for (int i = 0; i < 32; ++i) {
        int flag = 1 << i;
        std::cout << "i " << i << ", flag " << flag << std::endl;
    }
    auto ans = hammingDistance(1, 4);
    std::cout << "ans " << ans << std::endl;
    return 0;
}
