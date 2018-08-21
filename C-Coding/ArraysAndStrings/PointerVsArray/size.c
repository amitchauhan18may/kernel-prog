#include <stdio.h>

int main () {
    int arr[] = {10, 20, 30, 40, 50};
    int *ptr = arr;

    printf("Sizeof(arr) = %zu\n", sizeof(arr));
    printf("Sizeof(ptr) = %zu\n", sizeof(ptr));
    return 0;
}
