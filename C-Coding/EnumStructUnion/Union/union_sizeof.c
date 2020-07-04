#include <stdio.h>
union u {
    struct ss {
        char s;
        int v;
    } xx;
}xu;

union {
    char arr[sizeof (double) + 1];
    double d;
} pad;

typedef union u_data
{
    struct {
        char c;
        int a;
        int d;
    } abc;
    union {
        int s;
        int d;
    }sd;
    double f;
    int elem;
} my_data;


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
    printf("Sizeof union2: %ld\n", sizeof(my_data));
    printf("Sizeof Pad2: %ld\n", sizeof(pad));
    printf("Sizeof xu: %ld\n", sizeof(xu));
    return 0;
}
