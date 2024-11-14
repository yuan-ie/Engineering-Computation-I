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

    /* store the content in a buffer and print the content line by line*/

    FILE *file = fopen(argv[1],"r");
    if (file == NULL){
        fprintf(stderr, "Error: Can't open file.", argv[0]);
        return 1;
    }    

    char buffer[MAX_LINE_LENGTH];

    int len;
    int line_count = 0;

    while (fgets(buffer, sizeof(buffer), file)){
        len = strlen(buffer);
        char* tmp_string = new char[len+1];

        printf("%d: ", line_count);
        snprintf(tmp_string, len+1,"%s",buffer);
        printf("(%d) %s", strlen(tmp_string), tmp_string);

        line_count++;
        delete[] tmp_string;
    }

    fclose(file);
    

}