#include <stdio.h>

enum A {
    x, y=5,
    enum B {
        p=10,q
    }varp;
}varx;

int main (void) {

    printf("%d %d", x, varx.varp.q);

    return 0;

}
