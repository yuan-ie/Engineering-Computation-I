#include "lib.h"

void power_loop(int x, int y){
    int product = 1;
    for (int i=0; i<y; i++){
        product = product * x;
    }

    printf("For Loop: (%d ** %d) = %d\n", x, y, product);
}

void recursion(int x, int y, int tmp, int count){
    if (y == count){
        printf("Recursion: (%d ** %d) = %d\n", x, y, tmp);
        exit(0);
    }
    else {
        tmp = tmp * x;
        count ++;
        recursion(x, y, tmp, count);
    }
}

int main (int argc, char ** argv){
    if (argc != 3){
        fprintf(stderr, "Usage: %s <const> <const>\n", argv[0]);
        return 1;
    }

    int x = atoi(argv[1]);
    int y = atoi(argv[2]);

    power_loop(x, y);
    recursion(x, y, 1, 0);
}