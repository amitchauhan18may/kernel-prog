#include <stdio.h>
#include <stdlib.h>

int main () {
    int i = 54;
    float a = 3.14;
    char *ii, *aa;

    ii = (char *) &i;
    aa = (char *) &a;

    printf("Value at ii: %d\n", *ii);
    printf("Value at aa: %d\n", *aa);

    return 0;
}
