#include<stdio.h>

typedef struct A {
	int a;
	int b;
}A;
//Test about struct and typedef

typedef  A B;
int main() {
	B a = {1000};	
	printf("a.a = %d \n", a.a);
	printf("a.b = %d \n", a.b);
	return 0;
} 
