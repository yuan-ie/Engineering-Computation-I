#include <stdio.h>
#include <stdlib.h>

int main(void){
    for(int i=0; i<127; i++){
        fprintf(stdout,"the value of i is: %d\n", i);
    }
    bool status = true;
    long i = 0;
    printf("|DEC|HEX|OCT|ASCII|\n");
    while(status){
        char ascii = i;
        if (i < 32 || i > 126){
            char ascii[] = "NULL";
            printf("|%03d|%03X|%03o|%s|\n", i,i,i,ascii);
        }
        else
            printf("|%03d|%03X|%03o|%c|\n", i,i,i,ascii);
        i++;
        if(i==257){
            status = false;
        }
    }
}