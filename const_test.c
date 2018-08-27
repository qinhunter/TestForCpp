#include<stdio.h>

int main() {
	const char c = 'c';
	char* pc;
	pc = &c;

	const char** pcc = &pc;  //1: not allowed
	*pcc = &c;//same as	pc = &c

	*pc = 'C';  //2: modifies a const object
	// const char b = 'b';
	// char* pb;
	// pb = &b;// warning
	// printf("*pb = %c, char b = %c \n", *pb, b);
	// *pb = 'a';
	// printf("*pb = %c, char b = %c \n", *pb, b);
	// // b = 'd'; error


	return 0;
}

