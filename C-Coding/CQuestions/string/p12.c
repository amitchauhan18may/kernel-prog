#include <stdio.h>

int main (void) {

    int arr[2][3] = {5, 10, 15, 20, 25, 30};

    int (*ptr)[2][3] = &arr;

    printf("%d\t", ***ptr);
    printf("%d\t", ***(ptr + 1));
    printf("%d\t", **(*ptr + 1));
    printf("%d\t", *(*(*ptr + 1)+2));

    return 0;

}
