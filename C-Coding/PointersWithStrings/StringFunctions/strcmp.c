#include <stdio.h>
#include <ctype.h>


int xstrcmp (char *dest, char *source) {

    while (*source != '\0') {
        if (*dest != *source)
            return -1;
        source++;
        dest++;
    }

    return 0;
}


int xstrcmpi (char *dest, char *source) {

    while (*source != '\0') {
        if (toupper(*dest) != toupper(*source))
            return -1;
        source++;
        dest++;
    }

    return 0;
}


int main (void) {

    char str1[35] = "Amitji";
    char *str2 = "AmitJi";

    int result = xstrcmp(str1, str2);
    int resulti = xstrcmpi(str1, str2);

    printf("Str1: %s\nStr2: %s\n", str1, str2); 
    printf("After xstrcmp: %d\n", result);
    printf("After xstrcmpi: %d\n", resulti);

    return 0;

}
