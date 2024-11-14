all: t1 t2 t3

t1: t1.cc
	g++ t1.cc -o t1

t2: t2.cc
	g++ t2.cc -o t2

t3: t3.cc
	g++ t3.cc -o t3

debug:
	g++ -g -o t1 t1.cc

clean:
	rm -f t1 t2 t3