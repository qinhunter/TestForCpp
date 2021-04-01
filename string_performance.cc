#include <iostream> 
#include <stdlib.h> 
#include <time.h>  
#include <stdio.h>
#include <functional>
#include <time.h>

#include <stdarg.h>
#include <sstream>

using namespace std;  
const std::string& sep = "/";
const std::string& a = "part1";
const std::string& b = "part2";
const std::string& c = "part3";
const std::string& d = "part4";

constexpr int test_times = 10000000;

std::string string_add() {
    return sep + a + sep + b + sep + c + sep + d + sep;
}

std::string string_add_equal() {
    return (((((((((std::string() += sep) += a) += sep) += b) += sep) += c) += sep) += d) += sep);
}

std::string string_append() {
    return std::string().append(sep).append(a).append(sep).append(b).append(sep).append(c).append(sep).append(d).append(sep);
}

std::string stringstream_test() {
    std::stringstream ss;
    ss << sep << a << sep << b << sep << c << sep << d << sep;
    return ss.str();
}

double test_func(std::function<std::string()> test_func) {
    auto start = clock();
    for (int i = 0; i < test_times; ++i) {
        std::string s = test_func();
        s.clear();
    }
    auto end = clock();
    return static_cast<double>(end - start) / CLOCKS_PER_SEC;
}
int main() 
{  

    std::cout << "string_add " << std::to_string(test_func(string_add)) << std::endl;
    std::cout << "string_add_equal " << std::to_string(test_func(string_add_equal)) << std::endl;
    std::cout << "string_append " << std::to_string(test_func(string_append)) << std::endl;
    std::cout << "stringstream " << std::to_string(test_func(stringstream_test)) << std::endl;

	return 0; 
}
