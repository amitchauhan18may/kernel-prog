#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (void) {

    char *name[6];
    char str[30];
    int i;

    for (i = 0; i < 6; i++) {
        printf("Enter Name\n");
        gets(str);
        name[i] = (char *)malloc(strlen(str));
        strcpy(name[i], str);
    }

    for (i = 0; i < 6; i++) {
        printf("name[%d]: %s\n", i, name[i]);
    }

    return 0;
}
