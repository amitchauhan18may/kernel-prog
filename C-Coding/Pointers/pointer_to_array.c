#include <stdio.h>
#include <stdlib.h>

/* Syntex of an array
 * data_type (*var_name)[size_of_array];
 * */

int main (void) {
    int *p;
    int (*ptr)[5];
    int arr[5];

    p = (int *)&arr;
    ptr = &arr;

    printf("\np: %p  | ptr: %p\n", p, ptr);

    p++;
    ptr++;
    printf("\nAfter increment p++ / ptr++\n");
    printf("\np: %p  | ptr: %p\n", p, ptr);
    return 0;
}
