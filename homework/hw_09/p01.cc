#include "p0.h"

int random_number(int min, int max) {    
    // Generate a random number in the range
    int value = min + rand() % (max - min + 1);;
    return value;
}

int main (int argc, char **argv){

    // usage message and exit if one arg not provided.
    if (argc != 4){
        fprintf(stderr, "Usage: %s <file.bin> <min> <max>\n", argv[0]);
        return 0;
    }

    FILE *file = fopen(argv[1], "wb");

    int f = 100;                      // frequency
    int samples = 64000;
    int fs = 8000;
    int amplitude = 10000;
    double duration = (double) samples / fs;
    double t;                        // time

    int16_t x;

    for (int i=0; i<samples; i++){
        
        // time of current sample
        t = (double) i / fs;
        // printf("%d %d\n", atoi(argv[3]), atoi(argv[4]));
        amplitude = random_number(atoi(argv[2]), atoi(argv[3]));

        // sine value
        x = (int16_t)(amplitude * sin(2 * M_PI * f * t));
        fwrite(&x, sizeof(int16_t), 1, file);
    }

    fclose(file);

    printf("Binary file '%s' created successfully with %d samples.\n", argv[1], samples);

    return 0;
}