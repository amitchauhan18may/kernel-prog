#include <stdio.h>

union union_1 {
    int a;
    char ch;
};

int main () {
    union union_1 u1;

    u1.a = 10;

    printf("Assigning value to u1.a = %d\nu1.ch =%d\n", u1.a, u1.ch);

    u1.ch = 1;

    printf("Assigning value to u1.ch = %d\nu1.a =%d\n", u1.ch, u1.a);

    return 0;
}
