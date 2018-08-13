#include <stdio.h>

int main () {
    int arr[5];
    arr[0] = 1;
    arr[1] = 2;
    arr[2] = 3;
    arr[7/2] = 4;
    arr[4] = 5;

    printf("arr[0] = %d arr[1] = %d arr[2] = %d arr[7/2] = %d arr[4] = %d\n",
            arr[0], arr[1], arr[2], arr[7/2], arr[4]);
    return 0;
}
