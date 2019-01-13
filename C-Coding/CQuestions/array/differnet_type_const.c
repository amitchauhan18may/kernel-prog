#include <stdio.h>

int main (void) {

    static int a = 11, b = 22, c = 33;

    int *arr[5] = {&a, &b, &c};

    int const * const *ptr = &arr[1];

    --ptr;

    printf("%d\n", **ptr);

}
