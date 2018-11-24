#include <stdio.h>

int main (void) {

    int *arr[4]; /*Array of Pointers*/
    int i = 30, j = 43, k = 32, l = 91, c;

    arr[0] = &i;
    arr[1] = &j;
    arr[2] = &k;
    arr[3] = &l;

    for (c = 0; c < 4; c++) {
        printf("%d\n", *(arr[c]));
    }

    return 0;

}
