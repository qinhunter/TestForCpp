#include<stdio.h>
#include<iostream>

#define TEST_PRECOMPILE(name1, name2) \
std::string get_##name1() {return #name1;} \
int name1##name2() {return 0;} \
int name1##_##name2() {return 1;} \
int name1() {return 2;} \
int name1##_map() {return 3;} \
int _##name1##_map() {return 4;} \

TEST_PRECOMPILE(q, w);

int main(int argc, char *argv[]) {
	std::cout << "test precompile" << std::endl;
    std::cout << "get_q(): " << get_q() << std::endl;
    std::cout << "qw(): " << qw() << std::endl;
    std::cout << "q_w(): " << q_w() << std::endl;
    std::cout << "q(): " << q() << std::endl;
    std::cout << "q_map(): " << q_map() << std::endl;
    std::cout << "_q_map(): " << _q_map() << std::endl;
}
