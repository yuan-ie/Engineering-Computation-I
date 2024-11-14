#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define RANDOM(x) ((rand()<<15) % (x*2 + 1) - x/64)

int main(int argc, char **argv){
    if (argc != 2){
        printf("Usage: %s <const>\n", argv[0]);
        return 1;
    }

    long int randnum = RANDOM(atoi(argv[1]));
    printf("%ld\n", randnum);
}

