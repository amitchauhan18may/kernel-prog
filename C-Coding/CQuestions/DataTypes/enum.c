#include <stdio.h>


const enum alfa {
    X,
    Y=5,
    Z
}p = 10;


int main (void) {

    enum alfa a, b;

    a = X;
    b = Z;

    printf("%d\n", a);
    printf("%d\n", b);
    printf("%d\n", p);
    printf("%d\n", a+b-p);

    return 0;

}
