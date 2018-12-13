#include <stdio.h>

extern int i;

int main (void) {

    do {

        do {
            printf("%o\n", i);
        } while (!-2);

    } while (0);

    return 0;

}
int i = 8;
