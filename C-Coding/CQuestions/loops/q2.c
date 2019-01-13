#include <stdio.h>

int main (void) {

    int i = 2, j = 2;

    while (i+1 ? --i : j++) {
        printf("%d\n", i);
    }

    return 0;

}
