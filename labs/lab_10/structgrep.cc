#include "lib.h"


int main (int argc, char **argv){

    // usage message and exit if one arg not provided.
    if (argc == 1){
        fprintf(stderr, "Usage: %s -n [lines] -w [word] <file1> <file2> ... <file>\n", argv[0]);
        return 0;
    }

    int number;
    int num_flag;

    char *word = word_check(argc, argv);
    num_lines(argc, argv, &number, &num_flag);
    char **files = file_list(argc, argv, &num_flag);

    // printf("word: %s, number: %d\n", word, number);

    char line[100];
    int i = 0;
    int count = 0;

    // go through each file
    while (files[i] != NULL){
        printf("===============\n");
        printf("File: %s\n", files[i]);
        FILE *file = fopen(files[i], "r");
        if (file == NULL){
            printf("Error: Cannot open file: %s\n", files[i]);
            printf("Skipping...\n");
            i++;
            continue;
        }

        // get the number of lines in the file
        while(fgets(line, 100, file) != NULL){
            count++;
        }
        fclose(file);

        check_for_word(files[i], word, number, count);

        i++;
        count = 0;
        
    }

}