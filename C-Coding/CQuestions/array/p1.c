#include <stdio.h>

int main (void) {

    int arr[5] = {100, 200, 300};
    int *ptr = arr;
    char *ptr1 = (char *) arr;

    printf("%d %d\n", *(ptr + 2), *(ptr1 + 4));
    printf("%d %d\n", *(ptr+1), *(ptr1+4));

    return 0;

}
