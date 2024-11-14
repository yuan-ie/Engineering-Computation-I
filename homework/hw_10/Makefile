all: p01 p02

p01: p01.o
	g++ p01.o -o p01
p01.o: p01.cc lib.h Makefile
	g++ -c p01.cc -o p01.o

p02: p02.o
	g++ p02.o -o p02
p02.o: p02.cc lib.h Makefile
	g++ -c p02.cc -o p02.o
# functs.o: functs.cc lib.h Makefile
# 	g++ -c functs.cc -o functs.o

debug:
	g++ -g -o p01 p01.cc

clean:
	rm -f p01 p01.o