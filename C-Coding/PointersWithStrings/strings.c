#include <stdio.h>

int main (void) {

    char str1[] = "Hello";
    char str2[10];

    char *s = "Good Morning";
    char *q;
/*
 * strings.c:11:10: error: assignment to expression with array type
     str2 = str1;
 */
//    str2 = str1;

    /*Below statements are valid*/
    q = s;
    printf("q: %s\n", q);

    q = str1;
    printf("q: %s\n", q);

    return 0;
}
