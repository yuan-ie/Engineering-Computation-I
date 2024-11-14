#include "p0.h"

int main (int argc, char **argv){

    // usage message and exit if one arg not provided.
    if (argc != 2){
        fprintf(stderr, "Usage: %s <file.bin>\n", argv[0]);
        return 0;
    }

    // error message if file cannot be opened.
    FILE *file = fopen(argv[1], "rb");
    if (file == NULL){
        fprintf(stderr, "Cannot open file: <%s>\n", argv[1]);
        return 0;
    }

    float number[2];

    while(fread(number, sizeof(float), 2, file) == 2){
        fprintf(stdout, "%.1f %.1f\n", number[0], number[1]);
    }

    fclose(file);

    return 0;
}