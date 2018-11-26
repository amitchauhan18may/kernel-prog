#include <stdio.h>

int main (void) {

    char *p = "Amit";
    char arr[] = "Amit";

    char *q = p;
    printf("p: %s\n", p);

    *(q+2) = 's';

    printf("p: %s\n", p);

    return 0;

}
