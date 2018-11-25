#include <stdio.h>

int main (void) {

    char name[55];

    printf("Enter your name\n");
    scanf("%s", name);

    printf("Hello %s!\n", name);

    return 0;
}
