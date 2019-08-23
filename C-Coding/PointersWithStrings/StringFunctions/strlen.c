#include <stdio.h>

int xstrlen (char *str) {

    int length = 0;

    while (*str != '\0') {
        str++;
        length++;
    }

    return length;

}

int main (void) {

    char arr[] = "Bamboozled";
    int len1, len2;

    len1 = xstrlen(arr);
    len2 = xstrlen("HumptyDumpty");

    printf("String = %s | Length = %d\n", arr, len1);
    printf("String = %s | Length = %d\n", "HumptyDumpty", len2);

    return 0;
}
