#include "lib.h"

double binary_to_decimal(char *binary){
    int decimal = 0;
    while (*binary != '\0'){
        decimal = decimal << 1;
        if (*binary == '1'){
            decimal = decimal | 1;
        }
        binary++;
    }
    return decimal;
}

int main (int argc, char ** argv){
    if (argc != 2){
        fprintf(stderr, "Usage: %s <binary>\n", argv[0]);
        return 1;
    }

    float decimal = binary_to_decimal(argv[1]);
    printf("binary %s, decimal %f\n", argv[1], decimal);

}