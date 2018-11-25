#include <stdio.h>

int main (void) {

    char *name[6];

    int i;

    for (i = 0; i < 6; i++) {
        printf("Enter Name\n");
        scanf("%s", name[i]);
        printf("%s", name[i]);
    }



    return 0;
}
