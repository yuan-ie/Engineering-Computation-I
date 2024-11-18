all: my_program

my_program: my_program.o class.o
	g++ my_program.o class.o -o my_program

my_program.o: my_program.cpp lib.h Makefile
	g++ -c my_program.cpp -o my_program.o

class.o: class.cpp lib.h Makefile
	g++ -c class.cpp -o class.o

clean:
	rm -f my_program.o my_program class.o