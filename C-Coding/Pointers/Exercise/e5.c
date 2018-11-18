#include <stdio.h>

int power(int **);

int main () {

    int a = 5, *aa;

    aa = &a;

    //a = power(&aa);
    power(&aa);

    printf("a = %d | address = %p\n", a, aa);

    return 0;
}

int power (int **ptr) {

    int b;
    b = **ptr ***ptr;
    return b;
}
