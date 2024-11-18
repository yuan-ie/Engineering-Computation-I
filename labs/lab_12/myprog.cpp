#include "lib.h"

int main(int argc, char ** argv){
    if (argc != 2){
        printf("Usage: %s <input file> <output file>\n", argv[0]);
        return 1;
    }

    MyMatrix matA;

    matA.read(argv[1]);
    matA.display();
    matA.isRectangle();
}