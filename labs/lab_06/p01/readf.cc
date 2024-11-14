#include <stdlib.h>
#include <stdio.h>

int main(int argc, const char** argv){
    if (argc != 3){
        fprintf(stdout,"invalid arguments.\n");
        fprintf(stdout,"usage: read.exe <file1> <file2>\n");
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
    char buffer[maxlen];
    char f1[5][maxlen], f2[5][maxlen];
    int i = 0;

    while(fgets(buffer, sizeof(buffer), file1)){
        // fprintf(stdout,"%s", buffer);
        snprintf(f1[i], sizeof(f1[i]), "%s", buffer);
        i++;
    }

    i = 0;

    while(fgets(buffer, sizeof(buffer), file2)){
        // fprintf(stdout,"%s", buffer);
        snprintf(f2[i], sizeof(f2[i]), "%s", buffer);
        i++;
    }

    for (int k=0; k<i; k++){
        fprintf(stdout,"%.1f\n", atof(f1[k]));
    }
    for (int k=0; k<i; k++){
        fprintf(stdout,"%.1f\n", atof(f2[k]));
    }

    fclose(file1);
    fclose(file2);
}