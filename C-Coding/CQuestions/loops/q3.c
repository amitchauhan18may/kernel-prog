#include <stdio.h>

int main (void) {

    int x = 011, i;

    for (i = 0; i < x; i += 3) {
        printf("Start:%d ", i);
        continue;
        printf("End");
    }

    return 0;

}
