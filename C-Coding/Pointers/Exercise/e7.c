#include <stdio.h>

int main () {
    char   *c = 4000;
    int    *i = 4000;
    long   *l = 4000;
    float  *f = 4000;
    double *d = 4000;

    printf("c = %p | c+1 = %p\n", c, c + 1);
    printf("i = %p | i+1 = %p\n", i, i + 1);
    printf("l = %p | l+1 = %p\n", l, l + 1);
    printf("f = %p | f+1 = %p\n", f, f + 1);
    printf("d = %p | d+1 = %p\n", d, d + 1);

    return 0;
}
