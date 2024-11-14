all: p01 p02 p03 p04 p05

p01: p01.o
	g++ p01.o -o p01
p01.o: p01.cc p0.h Makefile
	g++ -c p01.cc -o p01.o

p02: p02.o
	g++ p02.o -o p02
p02.o: p02.cc p0.h Makefile
	g++ -c p02.cc -o p02.o

p03: p03.o
	g++ p03.o -o p03
p03.o: p03.cc p0.h Makefile
	g++ -c p03.cc -o p03.o

p04: p04.o
	g++ p04.o -o p04
p04.o: p04.cc p0.h Makefile
	g++ -c p04.cc -o p04.o

p05: p05.o
	g++ p05.o -o p05
p05.o: p05.cc p0.h Makefile
	g++ -c p05.cc -o p05.o

debug:
	g++ -g -o p01 p01.cc

clean:
	rm -f p01 p02 p03 p01.o p02.o p03.o