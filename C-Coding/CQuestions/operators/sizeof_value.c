#include <stdio.h>

int main (void) {
    long double a;
    printf("%ld %ld %ld %ld\n", sizeof(3.14), sizeof(3.14f), sizeof(3.14L), sizeof(a));
}
