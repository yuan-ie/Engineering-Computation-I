#include <stdlib.h>
#include <stdio.h>

int main(int argc, const char** argv){
    if (argc != 4){
        fprintf(stdout,"invalid arguments.\n");
        fprintf(stdout,"usage: read.exe <file1> <file2> <constant>\n");
        return 1;
    }

    FILE *file1 = fopen(argv[1],"r");
    FILE *file2 = fopen(argv[2],"r");

    if (file1 == NULL) {
        perror("error opening file.\n");
        fclose(file1);
        fclose(file2);
        return 1;
    }

    if (file2 == NULL) {
        perror("error opening file.\n");
        fclose(file1);
        fclose(file2);
        return 1;
    }

    int maxlen = 100;

    // len is initially zero but will have updates of a new size when the buffer is longer or shorter
    size_t len = 0;
    ssize_t read;
    int line1, line2 = 0;
    // an array of pointers
    char *buffer1[maxlen];
    char *buffer2[maxlen];
    
    // getline parameters:
    // 0: **ptr (not sure) or &ptr (address of the pointer to store data)
    // 1: &len -> pointer to len
    // 2: file
    while((read = getline(&buffer1[line1], &len, file1)) != -1){
        // increment line count
        line1++;
        // reset length to 0
        len = 0;
    }

    // for(int i=0; i<line; i++){
    //     fprintf(stdout,"%.1f\n",atof(buffer1[i]));
    // }

    while((read = getline(&buffer2[line2], &len, file2)) != -1){
        // increment line count
        line2++;
        // reset length to 0
        len = 0;
    }

    // for(int i=0; i<line; i++){
    //     fprintf(stdout,"%.1f\n",atof(buffer2[i]));
    // }

    fclose(file1);
    fclose(file2);

    if(line1!=line2){
        fprintf(stdout,"vectors are not the same length.\n");
        return 0;
    }

    float prod = 0;
    float dot = 0;
    for(int n=1; n<line1; n++){
        prod = atof(buffer1[n]) * atof(buffer2[n]);
        dot += prod;
    }
    float z = dot + atof(argv[3]);

    fprintf(stdout,"z = %.4f\n", z);
}