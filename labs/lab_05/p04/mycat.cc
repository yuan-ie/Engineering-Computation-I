#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    FILE *file;

    char ch;
    // check if the file exists
    // if the file exists, read the file character by character
    if(file = fopen(argv[1],"r")){

        // while the last character is not EOF (End of File)
        while ((ch = fgetc(file)) != EOF){
            printf("%c", ch);
        }

        fclose(file);
        
        // printf("file exists.\n");
    }
    // else, it does not exist
    else
        printf("file does not exist.\n");
}