#include <stdio.h>

void main () {

    static main;
    int x;

    x = call(main);

    printf("%d", x);
}

int call (int address) {

    address++;
    return address;
}
