all:
	g++ -std=c++17 -O2 -c A.cpp -o A.o
	g++ -std=c++17 -O2 -c B.cpp -o B.o
	ar rcs libab.a A.o B.o
	g++ -std=c++17 -O2 main_use_b.cpp libab.a -o test_use_b
	g++ -std=c++17 -O2 main_not_use_b.cpp libab.a -o test_not_use_b
