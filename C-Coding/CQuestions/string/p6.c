#include <stdio.h>

int main (void) {

    //int const SIZE = 5;
    int SIZE = 5;
    int expr;

    //double arr[SIZE] = {2.0, 4.0, 6.0, 7.0, 8.0};
    double arr[5] = {2.0, 4.0, 6.0, 7.0, 8.0};

    expr = 1|2|3|4;

    printf("%f", arr[expr]);

    return 0;

}
