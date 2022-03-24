#include<stdio.h>

int add_one(int v) {
    return v + 1;
}
class A {
public:
    A(int val_) : val(add_one(val_)) {}
    int val;
};
//Test about struct and typedef

int main() {
    A a(1);
	return 0;
} 
