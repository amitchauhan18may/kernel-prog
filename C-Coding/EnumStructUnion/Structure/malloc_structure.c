#include <stdio.h>

struct my_struct {
    char c;
    int a;
    int b;
    int *arr;
};


int main () {
    int *p;
    printf("Sizeof structure my_struct: %lu and \nSize of: %lu\n",
            sizeof(struct my_struct), sizeof(p));
    return 0;
}
