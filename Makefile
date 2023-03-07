all: solver test

solver: src/ src/main/main.cpp
	g++ src/*.cpp src/main/main.cpp -std=c++20 -g -o solver -Isrc/

clean:
	rm -f *.o solver

test: src/* src/test/*
	g++ src/*.cpp src/test/* -lgtest -pthread -lgtest_main -std=c++20 -g -o test -Isrc/
