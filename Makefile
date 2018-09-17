.PHONY:all
all: pragma.o test.o attribute.o const_test.o devided0.o rand.o moveinvector.o test.o struct.o setwithvector.o

.PHONY:clean
clean:
	@echo "Cleaning *.o"
	@rm -rf *.o

pragma.o:pragma.cc
	@g++ -o $@ pragma.cc -std=c++11

const_test.o:const_test.c
	@gcc -o $@ const_test.c 

attribut.o:attribute.c
	@gcc -o $@ attribute.c

devided.o:devided0.cc
	@g++ -o $@ devided0.cc -std=c++11

rand.o:rand.cc
	@g++ -o $@ rand.cc -std=c++11

moveinvector.o:moveinvector.cc
	@g++ -o $@ moveinvector.cc -std=c++11

test.o:test.cc
	@g++ -o $@ test.cc -std=c++11

struct.o:struct.c
	@gcc -o $@ struct.c

setwithvector.o:setwithvector.cc
	@g++ -o $@ setwithvector.cc -std=c++11
