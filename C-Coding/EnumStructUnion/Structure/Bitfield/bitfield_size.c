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

struct bitfield2 {
    int bigfield1:31;     /* 32-bit word 1 begins */
    int bigfield2:31;     /* 32-bit word 2 begins */
    int littlefield1:1;
    int littlefield2:1;   /* 32-bit word 3 begins */
};

struct bitfield3 {
    int bigfield1:31;     /* 32-bit word 1 begins */
    int littlefield1:1;
    int bigfield2:31;     /* 32-bit word 2 begins */
    int littlefield2:1;
};

int main () {
    printf("Size of bitfield1: %lu-bytes\n", sizeof(struct bitfield1));
    printf("Size of bitfield2: %lu-bytes\n", sizeof(struct bitfield2));
    printf("Size of bitfield3: %lu-bytes\n", sizeof(struct bitfield3));
    return 0;
}
