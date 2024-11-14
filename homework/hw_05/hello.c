#include <stdio.h>
#include <stdlib.h>

int main(void){
    char ch;
    char buffer[200]; 
    char line[200];

    // print character by character
    // while((ch = fgetc(stdin)) != EOF)
    // {
    //     fprintf(stdout,"%c", ch);
    //     // putchar(ch); // works the same
    // }

    // print line by line
    while(fgets(buffer, sizeof(buffer), stdin) != NULL){
        fprintf(stdout,"%s", buffer);
    }
    return 0;
}