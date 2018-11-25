#include <stdio.h>

void print (int *a, int *b, int *c, int *d, int *e) {
    printf("%d %d %d %d %d\n", *a, *b, *c, *d, *e);
}

int main () {

    static int arr[] = {97, 98, 99, 100, 101, 102, 103, 104};

    int *ptr = arr+1;
    
    printf("ptr: %p | arr: %p  | arr+1: %p\n", ptr, arr, arr+1);

    printf("++ptr: %p\nptr--: %p\nptr++: %p\n++ptr: %p\n", ++ptr, ptr--, ptr++, ++ptr);

    print(++ptr, ptr--, ptr, ptr++, ++ptr);

    return 0;
}
