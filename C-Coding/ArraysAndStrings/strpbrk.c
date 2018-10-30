#include <stdio.h>
#include <string.h>

int main (void) {
    char a[] = "victory";
    char b[] = "a23";
    char c[] = "i22";

    char *ptr, *ptr1;

    ptr  = strpbrk(a, b);
    ptr1 = strpbrk(a, c);

    if (0 == ptr) {
        printf("No Match Found for b\n");
    } else {
        printf("Match Found for b\n");
    }

    if (0 == ptr1) {
        printf("No Match Found for c\n");
    } else {
        printf("Match Found for c: %s\n", ptr1);
    }

    return 0;
}
