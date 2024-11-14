#include "p0.h"

int count_elements(char *file){
    FILE *f = fopen(file, "rb");
    if (f == NULL){
        fprintf(stderr, "Cannot open file: %s\n", file);
        return 1;
    }

    int num_elements = 0;
    float value;

    while(fread(&value, sizeof(float), 1, f) == 1){
        num_elements++;
    }

    fclose(f);

    return num_elements;
}

int main (int argc, char **argv){

    // usage message and exit if one arg not provided.
    if (argc != 4){
        fprintf(stderr, "Usage: %s <file.bin> <N> <M>\n", argv[0]);
        return 0;
    }

    int N = atoi(argv[2]);
    int M = atoi(argv[3]);

    if (N == 0){
        fprintf(stderr, "N must be greater than 0!\n");
        return 0;
    }

    if (M != 3*N){
        fprintf(stderr, "M must be exactly 3 times bigger than N!\n");
        return 0;
    }

    float frame[N];
    float window[M];

    // initialize the buffers
    for (int n=0; n<N; n++){
        frame[n] = 0;
    }
    for (int m=0; m<M; m++){
        window[m] = 0;
    }

    // get the number of elements in the binary file
    int num_elements = count_elements(argv[1]);


    FILE *file = fopen(argv[1], "rb");
    if (file == NULL){
        fprintf(stderr, "Cannot open file: %s\n", argv[1]);
        return 1;
    }


    // fill the first window buffer
    float value;
    for (int n=N; n<(N*3); n++){
        if(fread(&value, sizeof(float), 1, file) == 1){
            window[n] = value;
        }
        else{
            window[n] = 0;
        }
    }

    int size = sizeof(window) / sizeof(window[0]);

    int buff_n = 0;

    for (int i=0; i<M; i++){
        printf("%6.0f ", window[i]);
    }
    printf("\n");

    for(int i=0; i<(num_elements/N - 1); i++){

        // moves multiple bytes
        memmove(window, window+N, (M-N)*sizeof(float));
        for (int m=(M-N); m<M; m++){
            if(fread(&value, sizeof(float), 1, file) == 1){
                window[m] = value;
            }
            else{
                window[m] = 0;
            }
            
        // moves one by one
        // for (int m=0; m<(M); m++){
            // if (m < M-N){
            //     memmove(&window[m], &window[m+N], sizeof(float));
            //     printf("%.1f ", window[m]);
            // }
            // else{
            //     if(fread(&value, sizeof(float), 1, file) == 1){
            //         window[m] = value;
            //         printf("%.1f ", window[m]);
            //     }
            //     else{
            //         window[m] = 0;
            //         printf("%.1f ", window[m]);
            //     }
            // }       
        }
        for (int i=0; i<M; i++){
            printf("%6.0f ", window[i]);
        }
        printf("\n");
    }


    fclose(file);

}