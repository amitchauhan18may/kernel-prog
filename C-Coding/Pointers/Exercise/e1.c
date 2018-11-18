#include <stdio.h>

int main () {

    int a, *b, **c, ***d, ****e;

    a = 10;
    b = &a;
    c = &b;
    d = &c;
    e = &d;

    printf("a = %d\n", a);
    printf("b = %p\n", b);
    printf("c = %p\n", c);
    printf("d = %p\n", d);
    printf("e = %p\n", e);

    printf("%d %d %d %d\n", a, a + *b, **c + ***d, ****e);

    return 0;
}
