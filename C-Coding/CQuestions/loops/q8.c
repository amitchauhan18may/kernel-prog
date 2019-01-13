#include <stdio.h>

int r(void);

int main (void) {

    for (r(); r(); r()) {
        printf("%d ", r());
    }

    return 0;

}

int r () {

    static int num = 7;

    return num--;

}
