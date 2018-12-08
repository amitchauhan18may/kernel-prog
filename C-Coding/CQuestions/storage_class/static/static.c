#include <stdio.h>

int main (void) {

    int const a = 5;
    static int b = 5;

    printf("b: %d\n", b);

    return 0;
}
