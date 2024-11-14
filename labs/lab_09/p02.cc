#include "p0.h"

int main (int argc, char **argv){

    // usage message and exit if one arg not provided.
    if (argc != 2){
        fprintf(stderr, "Usage: %s <file to write>\n", argv[0]);
        return 0;
    }

    // error message if file cannot be opened.
    FILE *file = fopen(argv[1], "r");
    if (file == NULL){
        fprintf(stderr, "Cannot open file: <%s>\n", argv[1]);
        return 0;
    }

    float value;
    char *name[50];

    // read each line and only extract needed information.
    while(fscanf(file,"%50s = %f", name, &value) == 2){
        printf("%s = %.1f\n", name, value);
    }

    fclose(file);

    // extract only the numbers
    file = fopen(argv[1], "r");
    while(fscanf(file,"%*s %*s %f",&value) == 1){
        printf("%.1f\n", value);
    }

    fclose(file);

    return 0;
}