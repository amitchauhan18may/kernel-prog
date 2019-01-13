#include <stdio.h>

struct A {
    int p;
    float f;
    long double *r;
};

int main (void) {

    struct A arr[10];

    printf("SIZEOF ARR: %ld\n", sizeof(arr));

    return 0;

}
