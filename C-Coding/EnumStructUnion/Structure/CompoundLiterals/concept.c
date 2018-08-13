#include <stdio.h>

int main () {
    int *p = (int []) {2, 3, 4};
    printf("%d, %d, %d\n", p[0], p[1], p[2]);
}
