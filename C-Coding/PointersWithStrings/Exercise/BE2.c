#include <stdio.h>
#include <string.h>

int main (void) {

    static char str1[] = "Good";
    static char str2[20];
    static char str3[30] = "Day";

    int l;

    l = strcmp(strcat(str3, strcpy(str2, str1)), strcat(str3, "good"));

    printf("l:%d\n", l);

    return 0;

}
