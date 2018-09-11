#include <stdio.h>

int main () {
    char arr[] = "Kumar";
    char *a = "amit";
#if 0
/* You can change "a" to point something else but
 * cannot change value at present ""*/
    a = arr;
    printf("a = %s\n", a);
#else
/* Below statement will compile successfully,
 * but will give segmentation fault*/
    *(a+0) = 'I';
    printf("a = %s\n", a);
#endif

    return 0;
}
