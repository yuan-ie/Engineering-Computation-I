#include <stdio.h>
#include <stdlib.h>

int main(int arcg, const char **argv){

    if(atof(argv[1]) == 1){
        /* CASE 1 */
        int *ptr; // this is a pointer. a pointer points to an address.
        int x = 1;
        ptr = &x; // no need to put *, since ptr is already a pointer type.
                // ptr is a pointer to x

        // this prints the address the pointer is pointing at (address of x)
        printf("value of x: %d\n", x);
        printf("address of ptr1: %d\n\n", ptr);

        /* CASE 2 */ // this is the same is case 1 with one less line.
        int y = 1;
        int *ptr2 = &y; // this pointer is now pointing to the address of x.
        printf("value of y: %d\n", y);
        printf("address of ptr2: %d\n\n", ptr2);

        /* CASE 3 */
        *ptr = 2; // dereferencing ptr to modify the value stored in this address (of x)
                //-- this changes the value of x.
        printf("value of x: %d\n", x);
        printf("value of x by dereferencing ptr: %d\n\n", *ptr);

        printf("value of y: %d\n", y);
        printf("value of y by dereferencing ptr: %d\n\n", *ptr2);

        /* CASE 4 */
        // int **ptr3 = &ptr; //ptr3 is a pointer to ptr.

        // or can be done this way:
        int **ptr3;
        ptr3 = &ptr;

        printf("value of ptr3 = address of ptr1: %d\n", ptr3);
        printf("value of dereferencing ptr3 = value of ptr1(address of x): %d\n\n", *ptr3);
        printf("value of double dereferencing ptr3 = value of x: %d\n\n", **ptr3);
    }

    if(atof(argv[1]) == 2){
        char string[5] = "star";
        char *str = string;

        printf("str: %s\n", str);
        printf("*str: %c\n", *str);
        printf("*(str+1): %c\n", *(str+1));
        printf("*(str+1): %c\n", *(str+1));
        printf("str[3]: %c\n", str[3]);
        printf("str[4]: %c\n", str[4]);
    }

    else{
        printf("str: %s\n", argv[1]);
    }


// to change the 
}
