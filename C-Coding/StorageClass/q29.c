#include <stdio.h>

void foo (int x , int y) {

    x += y;
    y += x;

    printf("x = %d\n", x);

    return;
}

int main (void) {

    int x = 5.5;

    foo(x, x);

    return 0;

}
