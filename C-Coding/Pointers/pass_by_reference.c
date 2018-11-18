#include <stdio.h>

void swap_value (int *a, int *b) {
    int temp;

    temp = *a;
    *a = *b;
    *b = temp;

    printf("Inside swap_value: a = %d | b = %d\n", *a, *b);

    return;
}

int main () {

    int a = 10;
    int b = 20;

    printf("Inside Main: a = %d | b = %d\n", a, b);

    swap_value(&a, &b);
    
    printf("Inside Main: a = %d | b = %d\n", a, b);

    return 0;
}
