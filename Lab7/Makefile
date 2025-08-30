all: tests

tests: tests.o sprite.o
	g++ tests.o sprite.o -o tests

tests.o: tests.cpp sprite.hpp
	g++ -c tests.cpp -std=c++11 -Wall

sprite.o: sprite.cpp sprite.hpp
	g++ -c sprite.cpp -std=c++11 -Wall

clean:
	rm *.o tests