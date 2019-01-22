#include <stdio.h>

int main (void) {

    struct bitfield {
        signed int a:3;
        unsigned int b:13;
        unsigned int c:1;
    };

    struct bitfield bit1 = {2, 14, 1};

    printf("%ld\n", sizeof(bit1));

    return 0;

}
