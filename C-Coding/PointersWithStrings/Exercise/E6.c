#include <stdio.h>

int main (void) {

    char str[10] = {0,0,0,0,0,0,0,0,0,0};
    char *s;
    int i;

    s = str;

    for (i = 0; i <= 9; i++) {
        if(*s)
            printf("%c", *s);
        s++;
    }

    return 0;

}
