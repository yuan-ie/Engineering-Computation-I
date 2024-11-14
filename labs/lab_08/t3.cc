#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LINE_LENGTH 9999

int count_lines(const char *f){
    FILE *file = fopen(f,"r");
    char buffer[MAX_LINE_LENGTH];
    int N = 0;

    if (file == NULL){
        fprintf(stderr, "Error: Can't open file.");
        return 0;
    }

    while (fgets(buffer, sizeof(buffer), file)){
        N++;
    }

    printf("Number of lines: %d\n", N);
    fclose(file);

    return N;

}

char **reads_2_mem(const char *f, int N){
    FILE *file = fopen(f,"r");
    char buffer[MAX_LINE_LENGTH];

    if (file == NULL){
        fprintf(stderr, "Error: Can't open file.");
        return NULL;
    }
    
    /* create an array with N strings */

    char **strs = new char*[N]; // array (strs) of N pointers

    /* store the content in a buffer and print the content line by line*/

    int len;
    int line = 0;

    while (line < N){
        strs[line] = new char[MAX_LINE_LENGTH];

        if((fgets(strs[line], MAX_LINE_LENGTH, file)) == NULL)
            break;
        printf("(%d) %s", strlen(strs[line]), strs[line]);

        line++;
    }

    fclose(file);

    return strs; // return the pointer to an array of strings
}

void print_content(char** strs, int N){
    for(int i=0; i<N; i++){
        printf("%s", strs[i]);
    }
}

void free_mem(char **strs, int N){
    for (int i = 0; i < N; i++) {
        delete[] strs[i]; // Free each allocated string
    }

    printf("Deallocated all memory.")
}

int main (int argc, const char **argv){

    if (argc == 1){
        fprintf(stderr, "Usage: %s <file.txt>", argv[0]);
        return 1;
    }
    if (argc > 2){
        fprintf(stderr, "Error: Too many arguments.", argv[0]);
        return 1;
    }

    int N;

    /* count the number of lines */
    N = count_lines(argv[1]);
    
    // pointer strs to array of strings
    char **array = reads_2_mem(argv[1], N);
    
    // print the contents of the array
    print_content(array, N);

    // free the memory
    free_mem(array,N);

}