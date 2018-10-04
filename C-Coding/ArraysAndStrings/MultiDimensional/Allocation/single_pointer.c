#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

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

    for (i = 0; i < row; i++) {
        for (j = 0; j < column; j++) {
            printf("Count:");
            printf("%d, ", count);
            printf("\n");
            *(arr + i*column + j) = ++count;
        }
    }

    for (i = 0; i < row; i++) {
        for (j = 0; j < column; j++) {
            printf("%d, ", *(arr + i*column + j)); 
            printf("\n");
        }
    }

    return 0;
}
