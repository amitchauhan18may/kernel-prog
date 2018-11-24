#include <stdio.h>

int main () {

    static int a[] = {0, 1, 2, 3, 4};
    static int *p[] = {a, a+1, a+2, a+3, a+4};

    printf("a: %p\n", a);
    printf("p[0]: %p\n", p[0]);
    printf("*(p[0]): %d\n", *(p[0]));
    printf("*(p[1]): %d\n", *(p[1]));

    return 0;

}
