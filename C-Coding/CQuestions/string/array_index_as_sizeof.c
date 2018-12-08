#include <stdio.h>

int main (void) {
    long double a;
    signed char b;
    int arr[sizeof(!a+b)];

    printf("%ld \n", sizeof(arr));

    return 0;
}
