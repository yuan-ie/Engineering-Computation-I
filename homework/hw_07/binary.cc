#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, const char **argv){

    // if there are no arguments
    if (argc == 0){
        printf("usage: binary <char1> <char2> ... <chari>\n");
        printf("only use one character for each argument.\n");
        return 1;
    }
    for (int i = 1; i < argc; i++){
        // printf("%s %d\n", argv[i], strlen(argv[i]));
        if (strlen(argv[i]) != 1){
            printf("argument %d is not one character.\n", i);
            return 1;
        }
    }
    
    for (int j = 1; j < argc; j++){
        int bits = sizeof(argv[j]); // 8 bytes long
        int decimal = (int) argv[j][0]; // casts to in (gives ASCII value)

        printf("%c => ", argv[j][0]);

        // start from highest bit (ex. bit 7 from bit 7-0)
        for (int b = bits - 1; b  >= 0; b--){
            bits = (decimal >> b) & 1;
            printf("%d", bits);
            }

        printf(" (%d)\n", decimal);
        
    }

    return 1;
}