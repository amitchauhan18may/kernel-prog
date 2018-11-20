#include <stdio.h>

int main (void) {

    int array[5][2] = {
                        {1,  2},
                        {3,  4},
                        {5,  6},
                        {7,  8},
                        {9, 10}
                      };

    int i, j;
    for (i = 0; i <=4 ; i++) {
        printf("Address of %d 1-d Array: %p\n", i, array[i]);
    }

    for (i = 0; i <=4 ; i++) {
        for (j = 0; j < 2 ; j++) {
            printf("%d\n", *(*(array+i)+j));
        }
    }

    return 0;

}
