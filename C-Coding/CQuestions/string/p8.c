#include <stdio.h>

int main (void) {

    char data[2][3][2] = {0, 1, 2, 3, 4, 5, 6, 8, 9, 10, 11};

    printf("%o\n", data[0][2][1]);

    return 0;

}
