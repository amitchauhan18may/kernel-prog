#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define MSG_SIZE    11

char *msg1 = "I am msg 1";
char *msg2 = "I am msg 2";
char *msg3 = "I am msg 3";

int main () {
    char input[MSG_SIZE] = {0};

    int pip[2];
    int i;

    if (pipe(pip) < 0) {
        printf("Failed to create pipe\n");
        return -1;
    }

    write(pip[1], msg1, MSG_SIZE);
    write(pip[1], msg2, MSG_SIZE);
    write(pip[1], msg3, MSG_SIZE);

    for (i = 0; i < 3; i++) {
        /* read pipe */
        read(pip[0], input, MSG_SIZE);
        printf("%s\n", input);
    }

    return 0;
}
