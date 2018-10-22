#include <stdio.h>
#include <stdlib.h>

int main (void) {

    int arr[2] = {1, 2};
    void *ptr = arr;

    printf("Sizeof(int): %ld\n", sizeof(int));

    ptr = ptr + sizeof(int);

    printf("%d\n", *(int *)ptr);

    return 0;

}
