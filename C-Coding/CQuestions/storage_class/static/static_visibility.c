#include <stdio.h>

int main (void) {
    {
        static int a = 5;
        printf("a: %d", a);
    }

    //printf("a: %d", a);
}
