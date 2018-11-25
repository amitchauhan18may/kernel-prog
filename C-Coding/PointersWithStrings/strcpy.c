#include <stdio.h>

int xstrcpy (char *dest, char *source) {

    while (*source != '\0') {
        *dest = *source;
        source++;
        dest++;
    }

    dest = '\0';
}


int main (void) {

    char str1[35];
    char *str2 = "AmitJi";

    xstrcpy(str1, str2);

    printf("Str1 After xstrcpy: %s\n", str1);

    return 0;

}
