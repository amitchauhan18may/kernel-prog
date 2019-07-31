#include <stdio.h>

union union1 {
    int a;/*Maximum size of union member = 4*/
    char b;
    float c;
};

union union2 {
    int a[50];/*Maximum size of union member 4 x 50 = 200*/
    double d;/*Padding will be done on the basis of max of datatype*/
};


int main () {
    printf("Sizeof union1: %ld\n", sizeof(union union1));
    printf("Sizeof union2: %ld\n", sizeof(union union2));
    return 0;
}
