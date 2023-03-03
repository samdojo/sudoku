all:
	g++ src/*.cpp src/main/main.cpp -std=c++2a -g -o solver -Isrc/
	g++ src/*.cpp src/test/* -lgtest -pthread -lgtest_main -std=c++2a -g -o test -Isrc/

clean:
	rm -f *.o solver

