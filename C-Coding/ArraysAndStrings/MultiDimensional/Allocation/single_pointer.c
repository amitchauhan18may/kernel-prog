#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#define NEW 0

int main () {
    int row = 3;
    int column = 4;
    int i, j, count = 0;
    int *arr = NULL;

    arr = (int *) malloc(row * column * sizeof(int));
    if (NULL == arr) {
        printf("%s\n", strerror(errno));
        return errno;
    }
/* Assigning values */
#if 0
    for (i = 0; i < row; i++) {
        for (j = 0; j < column; j++) {
#else
    for (i = 0; i < row*column; i++) {
#endif
            printf("Count:");
            printf("%d, ", count);
            printf("\n");
#if 0
            *(arr + i*column + j) = ++count;
#endif
            *(arr + i) = ++count;
        }
   // }
/* Printing values */
    for (i = 0; i < row; i++) {
        for (j = 0; j < column; j++) {
            printf("%d, ", *(arr + i*column + j));
            printf("\n");
        }
    }

    free(arr);

    return 0;
}
