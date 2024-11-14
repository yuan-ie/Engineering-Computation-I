#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
    // fprintf(stdout, "hello world\n");

    float sum = atof(argv[1]);
    fprintf(stdout,"file: %s constant: %f\n", argv[0], sum);
}
