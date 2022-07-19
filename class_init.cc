#include<stdio.h>

int add_one(int v) {
    return v + 1;
}
class A {
public:
    A(int val_) : val(add_one(val_)) {
        printf("val %d\n", val_);
    }
    int val;
};
//Test about struct and typedef
//
class B : public A {
public:
    B(int val) : a(1), A(val) {}
    A a;
};

int main() {
    // A a(1);
    B b(3);
	return 0;
} 
