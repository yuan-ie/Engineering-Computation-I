all: pointers

pointers: pointers.cc
	gcc pointers.cc -o pointers

debug:
	gcc -g -o pointers pointers.cc

clean:
	rm -f pointers