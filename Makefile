all: solver test

solver: src/*.cpp
	g++ src/*.cpp src/main/main.cpp -std=c++2a -g -o solver -Isrc/

clean:
	rm -f *.o solver

test: src/*.cpp src/test/*.cpp
	g++ src/*.cpp src/test/* -lgtest -pthread -lgtest_main -std=c++2a -g -o test -Isrc/
