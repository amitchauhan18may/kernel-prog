#include <stdio.h>

void disp_2_d_array_1 (int (*p)[4], int row, int column) {
    
    int i, j;
    int *q;

    for (i = 0; i < row; i++) {
        q = p + i;

        for (j = 0; j < column; j++) {
            printf("%d, ", *(q + j));
        }

        printf("\n");
    }

    return;

}

int main (void) {

    int arr[][4] = {
                     1, 2, 3, 4,
                     5, 6, 7, 8
                   };

    disp_2_d_array_1(arr, 2, 4);

    return 0;

}
