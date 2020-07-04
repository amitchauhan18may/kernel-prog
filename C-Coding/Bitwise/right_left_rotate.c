#include <stdio.h>

unsigned right_rotate(unsigned char value, int n) {
    printf("LeftShift:%d\n", (8 * sizeof(value) - n));
    return ((value >> n) | ((value & (~(~0 << n))) << (8 * sizeof(value) - n)));
}

int main (void) {
    printf("After rotation: %d\n", right_rotate((unsigned char)3, 2));
    return 0;
}
