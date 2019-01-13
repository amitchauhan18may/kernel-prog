#include <stdio.h>

int main (void) {

    double num = 5.2;
    int var = 5;

    printf("%ld %ld %d\n", sizeof(!num), sizeof(var = 15/2), var);

}
