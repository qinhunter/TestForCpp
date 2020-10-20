.PHONY:all
all: precompile.o pragma.o test.o attribute.o const_test.o devided0.o rand.o moveinvector.o test.o struct.o setwithvector.o vectorusage.o RefLRValue.o

.PHONY:clean
clean:
	@echo "Cleaning *.o"
	@rm -rf *.o
	@rm -rf output

RefLRValue.o:RefLRValue.cpp
	@echo "g++ -o $@ RefLRValue.cpp -std=c++11"
	@echo "g++ -o no_elide_$@ RefLRValue.cpp -std=c++11 -fno-elide-constructors"
	@g++ -o $@ RefLRValue.cpp -std=c++11
	@g++ -o no_elide_$@ RefLRValue.cpp -std=c++11 -fno-elide-constructors

precompile.o:precompile.cc
	@echo "g++ -o $@ precompile.cc -std=c++11"
	@g++ -o $@ precompile.cc -std=c++11

pragma.o:pragma.cc
	@echo "g++ -o $@ pragma.cc -std=c++11"
	@g++ -o $@ pragma.cc -std=c++11

const_test.o:const_test.c
	@echo "gcc -o $@ const_test.c"
	@gcc -o $@ const_test.c 

attribut.o:attribute.c
	@echo "gcc -o $@ attribute.c"
	@gcc -o $@ attribute.c

devided.o:devided0.cc
	@echo "g++ -o $@ devided0.cc -std=c++11"
	@g++ -o $@ devided0.cc -std=c++11

rand.o:rand.cc
	@echo "g++ -o $@ rand.cc -std=c++11"
	@g++ -o $@ rand.cc -std=c++11

moveinvector.o:moveinvector.cc
	@echo "g++ -o $@ moveinvector.cc -std=c++11"
	@g++ -o $@ moveinvector.cc -std=c++11

test.o:test.cc
	@echo "g++ -o $@ test.cc -std=c++11"
	@g++ -o $@ test.cc -std=c++11

struct.o:struct.c
	@echo "gcc -o $@ struct.c"
	@gcc -o $@ struct.c

setwithvector.o:setwithvector.cc
	@echo "g++ -o $@ setwithvector.cc -std=c++11"
	@g++ -o $@ setwithvector.cc -std=c++11

vectorusage.o:vectorusage.cc
	@echo "g++ -o $@ vectorusage.cc -std=c++11"
	@g++ -o $@ vectorusage.cc -std=c++11
