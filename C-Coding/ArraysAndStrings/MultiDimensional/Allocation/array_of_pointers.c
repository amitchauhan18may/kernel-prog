#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#define NEW 0

int main () {
    int row = 3;
    int column = 4;
    int i, j, count = 0;
    int *arr[row];

    for (i = 0; i < row; i++) {
        arr[i] = (int *) malloc(column * sizeof(int));
        //if (NULL == arr[i]) {
        //    printf("%s\n", strerror(errno));
        //    return errno;
        //}
    }
/* Assigning values */
    for (i = 0; i < row; i++)
        for (j = 0; j < column; j++)
            arr[i][j] = ++count;

/* Printing values */
    for (i = 0; i < row; i++)
        for (j = 0; j < column; j++)
            printf("%d, ", arr[i][j]);

    return 0;
}
