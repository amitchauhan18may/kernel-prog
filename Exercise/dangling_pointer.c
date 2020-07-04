#include <stdio.h>
#include <stdlib.h>

int main (void) {

    int *ptr = (int *) malloc(10 * sizeof(int));

    free(ptr);

    *ptr = 20;/*It is a dangling pointer*/

    printf("%d\n", *ptr);

    return 0;

}
