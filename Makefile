all:
	g++ src/*.cpp -std=c++2a -g -o solver

clean:
	rm -f *.o solver

