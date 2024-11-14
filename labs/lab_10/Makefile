all: mygrep structgrep

# mygrep: mygrep.o
# 	g++ mygrep.o -o mygrep
# mygrep.o: mygrep.cc lib.h Makefile
# 	g++ -c mygrep.cc -o mygrep.o

structgrep: structgrep.o functs.o
	g++ structgrep.o functs.o -o structgrep
structgrep.o: structgrep.cc lib.h Makefile
	g++ -c structgrep.cc -o structgrep.o
functs.o: functs.cc lib.h Makefile
	g++ -c functs.cc -o functs.o

debug:
	g++ -g -o p01 p01.cc

clean:
	rm -f mygrep mygrep.o structgrep structgrep.o