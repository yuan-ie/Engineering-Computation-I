all: sort_int

sort_int: sort_int.o
	g++ sort_int.o -o sort_int
sort_int.o: sort_int.cc lib.h Makefile
	g++ -c sort_int.cc -o sort_int.o

# p02: p02.o
# 	g++ p02.o -o p02
# p02.o: p02.cc lib.h Makefile
# 	g++ -c p02.cc -o p02.o
# functs.o: functs.cc lib.h Makefile
# 	g++ -c functs.cc -o functs.o

debug:
	g++ -g -o p01 p01.cc

clean:
	rm -f sort_int sort_int.o