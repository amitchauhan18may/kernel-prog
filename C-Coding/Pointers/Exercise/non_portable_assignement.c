#include <stdio.h>

int *chk(int, int);

int main () {

    int *c;

    c = chk(10, 20);

    printf("c = %p\n", c);
    return 0;
}

int *chk (int i, int j) {
    int *p, *q;

    p = &i;
    q = &j;

    if (i >= 45) {
        printf("p = %p\n", p);
        return p;
    } else{
        printf("q = %p\n", q);
        return q;
    }

}
