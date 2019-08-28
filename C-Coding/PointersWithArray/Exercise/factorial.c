#include <stdio.h>

int factorial (int num) {

    if (num == 1)
        return 1;

    return num * factorial(num-1);

}


int main (void) {

    //int res = 1;
    int num = 4;

//    while (num != 1) {
//         res *= num;
//         num = num - 1;
//    }
//
//    printf("Res: %d\n", res);
    printf("Res: %d\n", factorial(num));

}
