#include <stdio.h>

int main (void) {
    {
        static int a = 5;
XY:;
        a++;
        printf("a: %d", a);
    }

    if (a < 10)
        goto XY;
    //printf("a: %d", a);
}
