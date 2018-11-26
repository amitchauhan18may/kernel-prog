#include <stdio.h>
//#include <string.h>
/*
local_strcpy_calling.c:4:13: warning: conflicting types for built-in function ‘strcpy’ [-Wbuiltin-declaration-mismatch]
 static void strcpy( char *destination, const char *source) {
*/
static void strcpy( char *destination, const char *source) {
    printf("Calling Function : %s\n", __func__);

    while (*destination++ = *source++);

    return;
}


int main (void) {

    char str1[] = "Amit Chauhan";
    char str2[40];

    strcpy(str2, str1);

    printf("Str2: %s\n", str2);

    return 0;

}

