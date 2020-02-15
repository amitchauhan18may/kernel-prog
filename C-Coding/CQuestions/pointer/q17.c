#include <stdio.h>

int test_extern_visibility () {
    extern int x;
    printf("%s: %d\n", __func__, x);
}

int main (void) {

extern int x;
    printf("main x = %d\n", x);
    test_extern_visibility();
    return 0;
}
