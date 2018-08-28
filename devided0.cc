#include <iostream>

// to see when is wrong. compiling? running?
int main(void) {

	int a = 1;
	a = a / 0;
	int b = 0;
	a = a / b;
}
