#include <stdio.h>

int main (void) {

    int a = 1;
    int b = 1;

    int *p = &a;
    int *q = &b;
    int c = p - q;

    printf("c = %d", q-p);

    return 0;

}
