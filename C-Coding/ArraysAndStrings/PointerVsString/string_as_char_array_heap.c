#include <stdio.h>
#include <stdlib.h>

int main () {
    char *a = NULL;
    a = (char *)malloc(4 * sizeof(char));
    if (a == NULL) {
        printf("Failed to allocate memory\n");
    }
    *(a+0) = 'a';
    *(a+1) = 'm';
    *(a+2) = 'i';
    *(a+3) = 't';

    printf("a = %s\n", a);
    *(a+0) = 'I';
    printf("after change\n");
    printf("a = %s\n", a);
    return 0;
}
