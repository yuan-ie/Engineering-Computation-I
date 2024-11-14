#include "p0.h"

int main (int argc, char **argv){

    // usage message and exit if one arg not provided.
    if (argc != 3){
        fprintf(stderr, "Usage: %s <file.bin> <const>\n", argv[0]);
        return 0;
    }

    // error message if file cannot be opened.
    FILE *file = fopen(argv[1], "w");
    // if (file == NULL){
    //     fprintf(stderr, "Cannot open file: <%s>\n", argv[1]);
    //     return 0;
    // }

    int value = atof(argv[2]);
    short int array[value];

    // size_t -> number of bytes
    // write numbers as binary to file
    for (short int i=0; i<value; i++) {
        array[i] = (short int)i;
    }

    fwrite(array, sizeof(short int), value, file);

    fclose(file);

    return 0;
}