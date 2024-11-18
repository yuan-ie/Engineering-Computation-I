all: myprog

myprog: myprog.o matrix.o
	g++ myprog.o matrix.o -o myprog

myprog.o: myprog.cpp lib.h Makefile
	g++ -c myprog.cpp -o myprog.o

matrix.o: matrix.cpp lib.h Makefile
	g++ -c matrix.cpp -o matrix.o

debug:
	g++ -g -o p01 p01.cc

clean:
	rm -f myprog.o myprog matrix.o