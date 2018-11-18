#include <stdio.h>

int main () {

    int i = 10, j = 20, diff;

    diff = &j - &i;

    printf("Address of j = %p | Address of i = %p\n", &j, &i);
    printf("Difference: %d\n", diff);

    return 0;
}
