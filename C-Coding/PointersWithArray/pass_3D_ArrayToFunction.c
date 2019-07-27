#include <stdio.h>

void print_3d_array_func1 (int *q, int a, int b, int c) {

    printf("Calling Function: %s\n", __func__);

    int i, j, k;

    for (i = 0; i < a; i++) {
        for (j = 0; j < b; j++) {
            for (k = 0; k < c; k++) {
                printf("%d, ", *(q + i*b*c + j*c + k));
            }
            printf("\n");
        }
        printf("\n\n");
    }

    return;
}


void print_3d_array_func2 (int (*p)[3][4], int a, int b, int c) {

    printf("Calling Function: %s\n", __func__);

    int i, j, k;
    int *q;

    for (i = 0; i < a; i++) {
        q = (int *)p + i;

        for (j = 0; j < b; j++) {
            for (k = 0; k < c; k++) {
                printf("%d, ", *(q + j*c + k));
            }
            printf("\n");
        }
        printf("\n\n");
    }

    return;
}


void print_3d_array_func3 (int q[][3][4], int a, int b, int c) {

    printf("Calling Function: %s\n", __func__);

    int i, j, k;

    for (i = 0; i < a; i++) {
        for (j = 0; j < b; j++) {
            for (k = 0; k < c; k++) {
                printf("%d, ", q[i][j][k]);
            }
            printf("\n");
        }
        printf("\n\n");
    }

    return;
}


int main () {
    
    int i, j, k;

    int a[2][3][4] = {
                        {
                          {1, 2, 3, 4},
                          {5, 6, 7, 8},
                          {9, 10, 11, 12}
                        },

                        {
                          {11, 12, 13, 14},
                          {15, 16, 17, 18},
                          {19, 21, 24, 21}
                        }
                     };

    //print_3d_array_func1((int *)a, 2, 3, 4);
    print_3d_array_func2(a, 2, 3, 4);

    return 0;
}
