#include <stdio.h>

int main (void) {

    int* (*array)[5];
    int *arr_of_pointers[5]; 
    int arr1[] = {1,  2};
    int arr2[] = {3,  4};
    int arr3[] = {5,  6};
    int arr4[] = {7,  8};
    int arr5[] = {9, 10};
    arr_of_pointers[0] = arr1;
    arr_of_pointers[1] = arr2;
    arr_of_pointers[2] = arr3;
    arr_of_pointers[3] = arr4;
    arr_of_pointers[4] = arr5;
    array = &arr_of_pointers;
    int i, j;

    for (i = 0; i <=4 ; i++) {
        for (j = 0; j < 2 ; j++) {
            printf("%d\n", *(*(*array+i)+j));
        }
    }

    return 0;

}
