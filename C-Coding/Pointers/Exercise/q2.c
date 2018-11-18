#include <stdio.h>

int main () {

    int a, b = 5;

    a = b + NULL;

    printf("a = %d\n", a);
   
    printf("SizeOf NULL  = %ld\n", sizeof(NULL));
    printf("SizeOf int * = %ld\n", sizeof(int *));
    printf("SizeOf ""("")" "   = %ld\n", sizeof(""));

    return 0;
}
