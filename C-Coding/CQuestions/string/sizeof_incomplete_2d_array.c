#include <stdio.h>

int main (void) {

    int arr[][3] = {{1, 2}, {3, 4, 5}, {5}};

    printf("sizeof(arr): %ld %d %d\n", sizeof(arr), arr[0][2], arr[1][2]);

    return 0;

}
