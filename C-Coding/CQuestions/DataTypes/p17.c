#include <stdio.h>

const enum cricket {
    Tylor,
    Kallis = 17,
    Chanderpaul
};

enum cricket x=Tylor | Kallis & Chanderpaul;
extern enum cricket x;

int main (void) {
    printf("%d", x);

    return 0;

}
