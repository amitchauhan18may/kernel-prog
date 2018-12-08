#include <stdio.h>

enum power {
    Dalai,
    Vladimir=3,
    Barack,
    Hillary
};

int main (void) {

    float leader[Dalai+Hillary] = {1.f, 2.f, 3.f, 4.f, 5.f};
    enum power p = Barack;

    printf("%0.f", leader[p>>1+1]);


    return 0;

}
