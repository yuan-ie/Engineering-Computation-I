#include "lib.h"

// option: -w (required)
char *word_check(int argc, char **argv){
    char *option_key = new char[10];
    int word_flag = 0;
    
    for (int i=1; i<argc; i++){
        if (strcmp(argv[i], "-w") == 0){
            // option n is at end of arguments
            if (i+1 == argc){
                printf("No word inputted for option -w.\n");
                exit(1);
            }
            else
                strcpy(option_key,argv[i+1]);
                word_flag = 1;
        }
    }
    if (word_flag == 0){
        printf("Word required to check files.\n");
        exit(1);
    }
    return option_key;
}

// option: -n
int num_lines(int argc, char **argv){
    int option_key = 0;
    for (int i=1; i<argc; i++){
        if (strcmp(argv[i], "-n") == 0){
            // option n is at end of arguments
            if (i+1 == argc){
                printf("No number inputted for option -n. Default to 0.\n");
                return 0;
            }
            else
                option_key = atoi(argv[i+1]);
        }
    }
    return option_key;
}

char **file_list(int argc, char **argv){
    int file_count = argc - 5; // excludes program, options, and option values
    char **files = new char*[file_count];
    int f = 0;
    for (int i=1; i<argc; i++){
        if ((strcmp(argv[i], "-n") != 0) && strcmp(argv[i], "-w") != 0){
            if ((strcmp(argv[i-1], "-n") == 0) || strcmp(argv[i-1], "-w") == 0){
                continue;
            }
            else {
                files[f] = new char[256];
                strcpy(files[f], argv[i]);
                f++;
                
                
            }
        }
    }

    return files;
}

void check_for_word(char *file, char *word, int number, int line_count){
    FILE *f = fopen(file, "r");

    // fill in the array with lines
    char **lines = new char*[line_count];
    for (int k=0; k<line_count; k++){
        lines[k] = new char[100];

        fgets(lines[k], 100, f);

    }

    for (int i=0; i<line_count; i++){
        if (strstr(lines[i], word) != NULL){
            if (i <= number){
                for (int L=0; L<i; L++){
                    printf("%s", lines[L]);
                }
            }
            else{
                for (int L=i-number; L<i; L++){
                    printf("%s", lines[L]);
                }
            }
            printf("-> %s", lines[i]);
            if(i >= line_count - number - 1){
                for (int L=i+1; L<line_count; L++){
                    printf("%s", lines[L]);
                }
            }
            else{
                for (int L=i+1; L<i+number+1; L++){
                    printf("%s", lines[L]);
                }
            }
            
        }
    }

    fclose(f);

    
}

int main (int argc, char **argv){

    // usage message and exit if one arg not provided.
    if (argc == 1){
        fprintf(stderr, "Usage: %s -n [lines] -w [word] <file1> <file2> ... <file>\n", argv[0]);
        return 0;
    }

    char *word = word_check(argc, argv);
    int number = num_lines(argc, argv);
    char **files = file_list(argc,argv);

    // printf("word: %s, number: %d\n", word, number);

    char line[100];
    int i = 0;
    int window_size = 2 * number + 1;
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