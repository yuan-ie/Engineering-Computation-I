#include "lib.h"

struct Buffer {
    int n;
    char word[LINE_SIZE];
    int window_size;
    char **window;
};

void initBuffer(struct Buffer *b, int n, char *word){
    b->n = n;
    b->window_size = n * 2 + 1;
    strcpy(b->word, word);
    b->window = new char*[b->window_size];
    for (int k=0; k<b->window_size; k++){
        // b->window[k] = new char[LINE_SIZE];
        b->window[k] = (char*)calloc(LINE_SIZE, sizeof(char));
    }
}

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
            else {
                strcpy(option_key,argv[i+1]);
                word_flag = 1;
            }
        }
    }
    if (word_flag == 0){
        printf("Word required to check files.\n");
        exit(1);
    }
    return option_key;
}

// option: -n
void num_lines(int argc, char **argv, int *option_key, int *num_flag){
    *option_key = 0;
    *num_flag = 0;

    for (int i=1; i<argc; i++){
        if (strcmp(argv[i], "-n") == 0){

            (*num_flag)++;
            // option n is at end of arguments
            if (i+1 == argc){
                printf("No number inputted for option -n. Default to 0.\n");
                // exit(100);
            }
            else {
                *option_key = atoi(argv[i+1]);
                (*num_flag)++;
            }
        }
    }
    
}

char **file_list(int argc, char **argv, int *num_flag){
    // printf("num flag %d\n", *num_flag);
    int file_count = argc - 3 - *num_flag; // excludes program, options, and option values

    printf("%d files\n", file_count);
    if (file_count == 0){
        printf("No files included.\n");
        exit(100);
    }

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

    Buffer buffer;
    initBuffer(&buffer, number, word);
    int null_count = 0;

    int i = 0;

    // fetch the first window
    for (int i=buffer.n; i<buffer.window_size; i++){
        if (fgets(buffer.window[i], LINE_SIZE, f)==nullptr){
            break;
        }
    }

    int k = buffer.n;
    while (buffer.window[k] != NULL){
        if (strstr(buffer.window[k], word) != NULL){
            for (int L=0; L<buffer.window_size; L++){
                if (buffer.window[L] == nullptr){
                    continue;
                }
                if (L == buffer.n){
                    printf("-> %s", buffer.window[L]);
                }
                else {
                    printf("%s", buffer.window[L]);
                }
            }
        }
        // printf("\n");
        memmove(buffer.window[k-buffer.n], buffer.window[k-buffer.n+1], (buffer.window_size-1-null_count)*LINE_SIZE);
        if(fgets(buffer.window[buffer.window_size-1-null_count], LINE_SIZE, f)==NULL){
            free(buffer.window[buffer.window_size-1-null_count]);
            buffer.window[buffer.window_size-1-null_count] = NULL;
            null_count++;
        }
    }

    fclose(f);
    
}