#include <stdio.h>
#include <string.h>

int main () {
    char arr[20] = "amit";
/* risky_gets.c:(.text+0x3b): warning: the `gets' function
 * is dangerous and should not be used. This finction is
 * completely removed from C-11*/
    gets(arr);
    printf("%s\n", arr);

    return 0;
}
