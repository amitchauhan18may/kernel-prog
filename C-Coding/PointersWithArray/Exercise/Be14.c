#include <stdio.h>

int main (void) {

    int arr[3][3][3];

    printf("arr:       %p | arr+1:     %p arr[1]:    %p\n", arr, arr+1, arr+2);
    printf("arr[0]:    %p | arr[0]+1:  %p arr[1]:    %p\n", arr[0], arr[0]+1, arr[1]);
    printf("arr[1][1]: %p | arr[1][0]: %p arr[0][1]: %p\n", arr[1][1], arr[1][0], arr[0][1]);

    return 0;

} 
