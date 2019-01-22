#include <stdio.h>

int main (void) {

    struct bitfield {
        unsigned a:3;
        char b;
        unsigned c:5;
        int d;
    }bit;


    printf("%ld\n", sizeof(bit));

    return 0;

}
