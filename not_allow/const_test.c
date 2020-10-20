#include<stdio.h>

void test1(void) {

	const char c = 'c';
	char* pc;
	pc = &c;

	const char** pcc = &pc;  //1: not allowed
	*pcc = &c;//same as	pc = &c

	*pc = 'C';  //2: modifies a const object

}

void test2(void) {

	const char b = 'b';
	char* pb;
	pb = &b;// warning
	printf("*pb = %c, char b = %c \n", *pb, b);
	*pb = 'a';
	printf("*pb = %c, char b = %c \n", *pb, b);
	// b = 'd';//this will be error

}

void test3(void) {
	
	char *header = "abcdef";//the char string is const and is saved in .rodata section which is can only be read and not write 
	char *p = header;
	printf("*p = %c, header = %s \n", *p, header);
	*p = 'H';//Run error: Bus error: 10
	printf("*p = %c, header = %s \n", *p, header);

}

int main() {
	test1();
	test2();
	test3();

	return 0;
}

