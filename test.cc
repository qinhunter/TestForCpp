#include <iostream> 
#include <stdlib.h> 
#include <time.h>  
#include <stdio.h>

#include <stdarg.h>

using namespace std;  




int max(int a, int b) {
	return a > b ? a : b;
}

// double max(int a, int b) {
// 	return a > b ? a : b;
// }
// functions that differ only in their return type cannot be overloaded


int sum(int count, ...)
{
	// the function that has unknown parameters
	int sum_value = 0;
 
	va_list args;
	va_start(args, count);
	printf("there should be %d parameters \n", count);
	int i = 0;
	while(count--)
	{
		i++;
		int temp = va_arg(args, int);
		printf("paramter %d: %d \n", i, temp);
		sum_value += temp;
	}
	va_end(args);
 
	cout << "the sum function with unknown parameters: sum_value = " << sum_value << endl;
	return sum_value;
}


class Base;
// function declaration

class Empty {
	// test the size of empty class
};

class HoldEmptyAndInt {
	// test the size of class holding an empty class
	int x = 0;
	Empty e;
};

class InheritEmpty: public Empty {
	// test the size of class inheriting an empty class
	private:
		int x = 0;
};

class HoldRefer {
	int i = 0;
	int& ref = i;
};

class ByteAlignment {
	// test the size of class with bit region and bytealignment
	int x = 0;
	char c1 = 0;
	char c2 = 0;
	long l = 0;
	char c3 = 0;
};

void testscope(int a, Empty emp) {
	// test the scope of function
	cout << "this is ::testscope: int a = " << a << endl;
	return;
}

class Base {
	public:
		Base() = default;
		Base(int A, int B = 2, int C = 4, unsigned int D = 10):a(A), b(B), c(C), d(D){}
		void display() {
			cout << "a = " << a << " b = " << b << " c = " << c << " d = "<< d << endl;
		}
		virtual void testsizeofvptr(void){}
		static void* operator new(size_t size, int newinputint) throw() {
			cout << "now is in Base operator new, and size = " << size << " newinputint = " << newinputint << endl;
			return ::operator new(size);
		}
		void testscope(string input) {
			cout << "this is testscope function in class Base: string input = " << input << endl;
			return;
		}
		// void testscopeinBase(int i, Empty emp, ByteAlignment balign) {
		// 	cout << "function testscopeinBase" << endl;
		// 	testscope(i, emp);
		// 	// too many arguments to function call, expected 1, have 2; did you mean '::testscope'?
		// 	return;
		// }
	private:
		friend void testfriend(class Base & Baseobj);	
		int a = 0;
		int b = 1;
		int c = 2;
		unsigned d : 3;
	public:
		virtual void virtualfunc(void) {
			cout << "private virtual function in Base" << endl;
		}
};

class Derived : public Base{
	private:
		virtual void virtualfunc(void) {
			cout << "virtual function in Derived" << endl;
		}
};

void testfriend(class Base & Baseobj) {
	// show the work of friend class and prove that it does not matter that where friend function of class is declared
	// for more, the 'testfriend' is declared in private but it can still be used well. I think it is because that friend function is not the part of the object of the class then the property of 'private' does not work on it.
	Baseobj.a = 1;	
}

void ShowSystemSize(void) {
	// show the size of different value in system
	cout << "sizeof char = " << sizeof(char) << endl;
	cout << "sizeof short = " << sizeof(short) << endl;
	cout << "sizeof int = " << sizeof(int) << endl;
	cout << "sizeof unsigned = " << sizeof(unsigned) << endl;
	cout << "sizeof long = " << sizeof(long) << endl;
	cout << "sizeof long long = " << sizeof(long long) << endl;
	cout << "sizeof long long int = " << sizeof(long long int) << endl;
	cout << "sizeof float = " << sizeof(float) << endl;
	cout << "sizeof double = " << sizeof(double) << endl;
	cout << "sizeof long double = " << sizeof(long double) << endl;
	cout << "sizeof pointer = " << sizeof(int*) << endl;
}

void ShowClassSize(void) {
	// show the size of empty class, class hoding empty and class inheriting empty class
	// show the byte alignment
	cout << "sizeof Empty = " << sizeof(class Empty) << endl;
	cout << "sizeof HoldEmptyAndInt = " << sizeof(HoldEmptyAndInt) << endl;
	cout << "sizeof InheritEmpty = " << sizeof(InheritEmpty) << endl;
	cout << "sizeof ByteAlignment = " << sizeof(ByteAlignment) << endl;
	cout << "sizeof Base = " << sizeof(class Base) << endl;
	cout << "sizeof HoldRefer = " << sizeof(HoldRefer) << endl;
}

void TestConstVolatile(void) {
	// test whether 'const' and 'volatile' can work together.
	int i = 0;
	const volatile int* cstvolptr = &i;
	cout << "*cstvolptr = " << *cstvolptr << endl;
	i = 3;
	cout << "*cstvolptr = " << *cstvolptr << endl;
}

// void TestConstFunc(void) const {}
// non-member function cannot have 'const' qualifier

int main() 
{  
	// ShowSystemSize();
	 ShowClassSize();

    class Base testA(10);
	testA.display();
	testfriend(testA);
	testA.display();

	// Base* testnew = new Derived;
	// no matching function for call to 'operator new'
	// test.cc:48:16: note: candidate function not viable: requires 2 arguments, but 1 was provided 
	Base* testb = new(10) Derived();
	testb->virtualfunc();
	free(testb);

	// TestConstVolatile();	
	// int sum_val = sum(10, 1, 2, 3, 4);

	return 0; 
}
