all: readf.exe

readf.exe: readf.o
	gcc readf.o -o readf

readf.o: readf.cc
	gcc -c readf.cc -o readf.o

clean:
	rm -f readf.o readf.exe