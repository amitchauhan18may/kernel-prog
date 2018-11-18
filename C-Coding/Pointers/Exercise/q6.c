#include <stdio.h>

float *func(float *);

int main () {

    float p = 23.5;
    float *q;

    q = &p;

    printf("Before q = %p\n", q);

    q = func(&p);
    
    printf("After  q = %p\n", q);
}

float *func (float *f) {

    f = f + 1;
    return f;
}
