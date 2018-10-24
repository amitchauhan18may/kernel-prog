#include <stdio.h>
/* Note that the purpose of restrict is to
 * show only syntax. It doesn't change anything
 * in output (or logic). It is just a way for
 * programmer to tell compiler about an optimization
 */

void use (int *a, int *b, int *restrict c) {
    *a += *c;
    *b += *c;
}

int main (void) {
    int a = 50, b = 60, c = 70;
    use(&a, &b, &c);
    /* Since c is restrict, compiler will
     * not reload value at address c in 
     * its assembly code. Therefore generated 
     * assembly code is optimized 
     */
    printf("a = %d, b = %d, c = %d\n", a, b, c);

    return 0;
}
