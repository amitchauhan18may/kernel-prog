#include <stdio.h>

int main () {

    int a[][4] = {
                   5, 7, 2, 5,
                   3, 1, 4, 2,
                   3, 0, 7, 1,
                 };

    int *p;
    int (*q)[4];

    p = (int *)a;
    q = a;

    printf("p: %p | q: %p\n", p, q);

    p++;
    q++;

    printf("p: %p | q: %p\n", p, q);
    return 0;

}
