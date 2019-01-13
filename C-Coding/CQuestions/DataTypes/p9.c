#include <stdio.h>

int main (void) {

    signed x, a;
    unsigned y, b;

    a = (signed) 10u;
    b = (unsigned) -10;

    y = (signed) 10u + (unsigned) -10;
    x = y;

    printf("%d %u\t", a, b);

    if (x == y) {
        printf("%d %d\n", x, y);
    } else if (x != y) {
        printf("%d %u\n", x, y);
    }

    return 0;

}
