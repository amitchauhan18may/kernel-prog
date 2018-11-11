#include <stdio.h>
#include <stdlib.h>

int main () {
    printf("Function: %d\n", func(10, 5));

    return 0;
}

int func (int x, int y, int c) {
    return x + y + c;
}
