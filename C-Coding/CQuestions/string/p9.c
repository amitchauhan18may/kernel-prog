#include <stdio.h>

int main (void) {

    short num[3][2] = {3, 6, 9, 12, 15, 18};

    printf("%d  %d\n", *(num+1)[1], **(num+2));

    return 0;

}
