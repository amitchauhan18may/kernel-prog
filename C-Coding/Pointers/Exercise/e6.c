#include <stdio.h>

float *multiply(int, float);

int main () {
    
    int i = 3;
    float f = 3.50, *prod;

    prod = multiply(i, f);

    printf("prod = %p | value at address: %f\n", prod, *prod);

    return 0;
}

float *multiply (int ii, float jj) {
    float product;

    product = ii * jj;

    printf("product = %f | Address of product: %p\n", product, &product);

    return (&product);
}
