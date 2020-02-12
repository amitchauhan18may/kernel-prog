#include <limits.h>
#include <stdio.h>

unsigned get_n_bits(unsigned value, int p, int n){
    return (value >> (p+1-n)) & ~(~0 << n);
}

unsigned set_n_bits(unsigned value, int p, int n){
/*Setting n-bits at From position p*/
    value |= (~(~0 << n)) << (p-1);
/*Returning set-bits value*/
    return (value >> (p+1-n)) & (~(~0 << n));
}

unsigned invert_n_bits(unsigned value, int p, int n){
    return (value ^ ((~(~0 << n)) << (p + 1 -n)));
}

int main (void) {

    printf("%d\n", get_n_bits(48, 5, 2));
    printf("%d\n", set_n_bits(48, 3, 2));
    printf("%d\n", invert_n_bits(60, 5, 2));

}
