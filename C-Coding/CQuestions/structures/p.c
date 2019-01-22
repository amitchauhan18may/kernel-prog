#include <stdio.h>

int main (void) {

    struct bitfield {
        unsigned a:5;
        unsigned c:5;
        unsigned b:6;
    }bit;

    char *p;

    struct bitfield *ptr, bit1={1, 3, 3};

    ptr = &bit1;

    ptr++;

    printf("%d", *p);

    return 0;
}
