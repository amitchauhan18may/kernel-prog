#include <stdio.h>

struct bitfield1 {
    short s;       /* 2 bytes */
    char c;        /* 1 byte */
    int flip:1;    /* total 1 bit */
    int nybble:4;  /* total 5 bits */
    int pad1:3;    /* pad to an 8-bit boundary */
    int septet:7;  /* 7 bits */
    int pad2:25;   /* pad to 32 bits */
};

int main () {
    printf("Size of bitfield1: %lu-bytes\n", sizeof(struct bitfield1));
    return 0;
}
