#include <stdio.h>

int main (void) {

    char name[] = "Amit";
    char *ptr;

    ptr = name;

    while (*ptr != '\0') {
        printf("%c", *ptr);
        ptr++;
    }
    printf("%s", name);
    printf("\n");
    return 0;
}
