#include <stdio.h>

/*
 * pointer_arithmatic.c:9:11: error: invalid operands to binary * (have ‘float *’ and ‘int’)
 *   j = j * 2;
 * pointer_arithmatic.c:10:11: error: invalid operands to binary / (have ‘float *’ and ‘int’)
 *   k = k / 2;
 */


int main (void) {

    float a[] = {13.2, 23.1, 34.1, 5.4, 1.4};
    float *j, *k;
    j = a;
    k = a + 4;
    j = j * 2;
    k = k / 2;

    printf("%f %f\n", *j, *k);

    return 0;
}
