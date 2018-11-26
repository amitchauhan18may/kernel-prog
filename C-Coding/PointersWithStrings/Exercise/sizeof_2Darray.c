#include <stdio.h>

int main (void) {

char *mess[] = {
                "Some love one",
                "Some love two",
                "I love one",
                "That is you"
               };

    printf("%ld %ld\n", sizeof(mess), sizeof(mess[1]));

    return 0;

}
