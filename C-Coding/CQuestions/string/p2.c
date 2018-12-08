#include <stdio.h>
#include <string.h>

int main (void) {

    char *ptr1 = NULL;
    char *ptr2 = 0;

    strcpy(ptr1, "C");
    strcpy(ptr2, "questions");

    printf("ptr1: %s| ptr2: %s\n", ptr1, ptr2);

    return 0;

}
