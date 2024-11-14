all: loop.exe

# compile object file as executable
loop.exe: loop.o
	gcc loop.o -o loop.exe

# compile cc file as object file
loop.o: loop.cc
	gcc -c loop.cc -o loop.o

clean:
	rm loop.o loop.exe