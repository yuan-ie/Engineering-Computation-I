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

    // int value = atof(argv[2]);
    float number;

    while(fread(&number, sizeof(float), 1, file) == 1){
        fprintf(stdout, "%.1f\n", number);
    }

    fclose(file);

    return 0;
}