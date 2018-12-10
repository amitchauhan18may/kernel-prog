#include <stdio.h>

void start();
void end();


#pragma startup start
#pragma exit end

void start () {
    printf("Start\n");
}

void end () {
    printf("End\n");
}

int main (void) {

    printf("Main\n");

    return 0;

}
