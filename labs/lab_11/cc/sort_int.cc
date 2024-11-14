#include "lib.h"

int compare_numbers (const void *v1, const void *v2){

    int a = *(const int *)v1;
    int b = *(const int *)v2;

    if ((a % 2 == 0) && (b % 2 == 0)){
        if (a < b) return -1;
        if (a == b) return 0;
        if (a > b) return 1;
    }
    if ((a % 2 != 0) && (b % 2 != 0)){
        if (a > b) return -1;
        if (a == b) return 0;
        if (a < b) return 1;
    }
    // if odd and even or even and off
    if (((a % 2 == 0) && (b % 2 != 0)) || ((a % 2 != 0) && (b % 2 == 0))){
        if (abs(a) < abs(b)) return -1;
        if (abs(a) == abs(b)) return 0;
        if (abs(a) > abs(b)) return 1;
    }
    return 0;
}

int main(int argc, char **argv){
    if (argc != 3){
        printf("Usage: %s <input file> <output file>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    int num;
    
    int num_elements = 0;

    // get the number of elements
    while(fscanf(file, "%d", &num) == 1){
        num_elements++;
    }

    rewind(file);

    // store all of the numbers in an array
    int *input_num = (int*)malloc(num_elements*sizeof(int));
    int i = 0;
    while(fscanf(file, "%d", &num) == 1){
        input_num[i] = num;
        i++;
    }

    fclose(file);

    qsort(input_num, i, sizeof(int), compare_numbers);

    FILE *file2 = fopen(argv[2], "w");

    for (int k=0; k<num_elements; k++){
        fprintf(file2, "%d\n", input_num[k]);
    }

    fclose(file2);

    free(input_num);
}