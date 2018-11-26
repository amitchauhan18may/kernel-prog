#include <stdio.h>

int main (void) {

    char string[] = "OddLengthString";
    char *ptr1, *ptr2;
    int i;

    ptr1 = string;
    ptr2 = string + strlen(string) - 1;

    for (i = 0; ptr1 != ptr2; i++) {
        ++ptr1;
        --ptr2;
        printf("%d ", i);
    }

    return 0;

}
