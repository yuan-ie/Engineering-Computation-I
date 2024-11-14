all: mycat

mycat: mycat.o
	gcc mycat.o -o mycat

mycat.o: mycat.cc
	gcc -c mycat.cc -o mycat.o

clean: rm mycat.o mycat