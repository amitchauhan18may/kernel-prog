#include <stdio.h>

void add (int a, int b) {
    printf("Addition of a+b = %d\n", a + b);
}

void subtract (int a, int b) {
    printf("subtraction of a-b = %d\n", a - b);
}

void multiply (int a, int b) {
    printf("Multiplication of a*b = %d\n", a * b);
}

int main () {
    void (*fun_pointer_array[])(int, int) = {add, subtract, multiply};
    fun_pointer_array[0](1,2);
    fun_pointer_array[1](1,2);
    fun_pointer_array[2](1,2);
    return 0;
}
