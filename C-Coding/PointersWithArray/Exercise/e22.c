#include <stdio.h>

int main () {

    static int a[] = {0,1,2,3,4};

    static int *p[] = {a,a+1,a+2,a+3,a+4};

    int **ptr = p;
    printf("ptr: %p\n", ptr);
    ptr++;
    printf("ptr++: %p\n", ptr);
    printf("%d %d %d\n", ptr -p, *ptr-a, **ptr);

    *ptr++;
    printf("*ptr++: %p\n", ptr);
    printf("%d %d %d\n", ptr -p, *ptr-a, **ptr);

    *++ptr;
    printf("*++ptr: %p\n", ptr);
    printf("%d %d %d\n", ptr -p, *ptr-a, **ptr);

    ++*ptr;
    printf("*++ptr: %p\n", ptr);
    printf("%d %d %d\n", ptr -p, *ptr-a, **ptr);

    return 0;
}
