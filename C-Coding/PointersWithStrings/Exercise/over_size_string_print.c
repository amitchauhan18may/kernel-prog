#include <stdio.h>
/*
 * over_size_string_print.c:5:19: warning: initializer-string for array of chars is too long
     char str[7] = "Stringsdfgr";

     But it will printf only 7-characters of string
 *
 * */

int main (void) {

    char str[7] = "Stringsdfgr";
    printf("%s\n", str);

    return 0;

}
