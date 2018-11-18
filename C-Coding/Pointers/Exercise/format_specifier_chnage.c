#include <stdio.h>

int main () {

    float a = 7.999999;
    float *b, *c;
    int int_val = 5;

    b = &a;
    c = b;

    printf("&a = %u| b = %u| c = %u\n", &a, b, c);
    printf("a = %d| *(&a) = %d| b = %d| c = %d\n", a, *(&a), *b, *c);
    printf("int_val = %f\n", int_val);
    printf("int_val = %d\n", int_val);
    return 0;
}
