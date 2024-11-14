#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LINE_LENGTH 9999

int main (int argc, const char **argv){
    if (argc == 1){
        fprintf(stderr, "Usage: %s <file.txt>", argv[0]);
        return 1;
    }
    if (argc > 2){
        fprintf(stderr, "Error: Too many arguments.", argv[0]);
        return 1;
    }

    /* count the number of lines */

    char buffer[MAX_LINE_LENGTH];
    int N = 0;

    FILE *file = fopen(argv[1],"r");
    if (file == NULL){
        fprintf(stderr, "Error: Can't open file.", argv[0]);
        return 1;
    }   

    while (fgets(buffer, sizeof(buffer), file)){
        N++;
    }

    printf("Number of lines: %d\n", N);

    fclose(file);

    /* create an array with N strings */

    char* strs[N]; // array of pointers

    /* store the content in a buffer and print the content line by line*/

    file = fopen(argv[1],"r");  

    int len;
    int line = 0;

    while (line < N){
        strs[line] = new char[MAX_LINE_LENGTH];

        if((fgets(strs[line], MAX_LINE_LENGTH, file)) == NULL)
            break;
        printf("(%d) %s", strlen(strs[line]), strs[line]);

        line++;
    }

    printf("%s", strs[0]);
    printf("%s", strs[1]);

    // Clean up: Free the allocated memory
    for (int i = 0; i < N; i++) {
        delete[] strs[i]; // Free each allocated string
    }

    fclose(file);

}