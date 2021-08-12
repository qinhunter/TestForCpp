#include<stdio.h>


template<typename T>
class A {
public:
    A (const T& a, const T& b) : _a(a), _b(b) {}
	T _a;
	T _b;
};

int main() {
	A a(1, 2);
	printf("a.a = %d \n", a._a);
	printf("a.b = %d \n", a._b);
	return 0;
}
