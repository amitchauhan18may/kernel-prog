#include <stdio.h>

void my_test_func(void) {
    printf("I am from: %s\n", __func__);
    return;
}
