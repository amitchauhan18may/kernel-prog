#include <stdio.h>

enum state {WORKING = 0, FAILED, FREEZD};
enum state current_state = 2;

enum state findState () {
    return current_state;
}

int main () {
    (findState() == WORKING) ? printf("WORKING\n") : printf("NOT-WORKING\n");
    return 0;
}
