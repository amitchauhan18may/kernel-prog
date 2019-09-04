#include <stdio.h>

int main () {
    int a = -1;
    int b = 1;

    if ((a ^ b) < 0)
        printf("Opposite sign\n");
    else
        printf("Same sign\n");

    return 0;

}
