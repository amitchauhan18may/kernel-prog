#include <stdio.h>
#include <stdlib.h>

int main (void) {
    int row = 3;
    int column = 4;
    int i, j, count = 0 ;
    int **arr;

    arr = (int **) malloc(row * sizeof(int *));

    for (i = 0; i < row; i++)
        arr[i] = (int *) malloc(column * sizeof(int));

    for (i = 0; i < row; i++)
        for (j = 0; j < column; j++)
            arr[i][j] = ++count;

    for (i = 0; i < row; i++)
        for (j = 0; j < column; j++)
           printf("%d, ", arr[i][j]);
    printf("\n");
    
    return 0;
}
