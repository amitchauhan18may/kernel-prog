#include <stdio.h>
#include <string.h>

int main (void) {

    int a, b, c, d;

    char *p = (char *)0;
    int *q = (int *)0;
    float *r = (float *)0;
    double *s = (double *)0;

    a = (int) (p+1);
    b = (int) (q+1);
    c = (int) (r+1);
    d = (int) (s+1);

    printf("%d %d %d %d\n", a, b, c, d);

    return 0;

}
