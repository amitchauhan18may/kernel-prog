#include <stdio.h>

void my_start_function (void) __attribute__ ((constructor));

void my_end_function (void) __attribute__ ((destructor));

void my_start_function (void) {
    printf("Before main\n");
    return;
}


void my_end_function (void) {
    printf("After main\n");
    return;
}


int main () {
    printf("Inside main\n");
    return 0;
}
