# file: lecture_05/GNUMakefile
#
# Note that this make file uses "-g" to compile and link "debug".
#

# define a target for the application
#
all: p01.exe

# compile example.o and output as exe file
# - contains math library, must use even if having include math library
# example.exe depends on example.o, so go to "example.o:" line
#
p01.exe: p01.o 
	gcc p01.o -o p01.exe

# define targets to compile the source code
#
p01.o: p01.cc
	gcc -O -c p01.cc -o p01.o

# define a debug target
#
debug:
	gcc -g -o p01.exe p01.cc

# define a target to clean the directory
#
clean:
	rm -f p01.o p01.exe

#
# end of file
