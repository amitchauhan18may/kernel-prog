#include <stdio.h>

struct test {
    unsigned int a: 5;
    unsigned int b: 8;
};

struct test2 {
    unsigned int a: 5;
    unsigned int : 0;
    unsigned int b: 8;
};

int main () {
    printf("Sizeof struct test: %lu\n", sizeof(struct test));
    printf("Sizeof struct test with firced alligned: %lu\n",
            sizeof(struct test2));
    return 0;
}
