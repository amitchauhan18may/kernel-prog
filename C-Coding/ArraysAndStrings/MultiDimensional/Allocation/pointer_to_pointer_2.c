#include <stdio.h>
#include <stdlib.h>

int main (void) {
    int row = 3;
    int column = 4;
    int i, j, count = 0 ;
    int **arr;

    arr = (int **) malloc(sizeof(int *) * row);
    arr[0] = (int *) malloc(sizeof(int) * column * row);

    for (i = 0; i < row; i++)
       arr[i] = (*arr + column * i);

    for (i = 0; i < row; i++)
        for (j = 0; j < column; j++)
            arr[i][j] = ++count;

    for (i = 0; i < row; i++)
        for (j = 0; j < column; j++)
           printf("%d, ", arr[i][j]);
    printf("\n");

    return 0;
}
