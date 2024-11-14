#include "p0.h"

int main (int argc, char **argv){

    // usage message and exit if one arg not provided.
    if (argc != 2){
        fprintf(stderr, "Usage: %s <file to write>\n", argv[0]);
        return 0;
    }

    FILE *file = fopen(argv[1], "w");

    fprintf(file,"width = 27.0\nheight = 99.0\nlength = 33.0");
    fclose(file);
    return 0;
}