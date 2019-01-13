#include <stdio.h>

int main (void) {

    int a = sizeof(signed) + sizeof(unsigned);
    printf("a = %d \n", a);
    int b = sizeof(const) + sizeof(volatile);
    printf("b = %d \n", b);

    printf("a+++b = %d\n", a+++b);

    return 0;

}
