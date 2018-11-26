#include <stdio.h>
/*
 *E24.c:17:14: error: assignment to expression with array type
     names[3] = names[4];
              ^
E24.c:18:14: error: assignment to expression with array type
     names[4] = t;
              ^

 * */

int main (void) {
    
    char names[5][20] = {
                         "Abcdef",
                         "ghi",
                         "jkl",
                         "mno",
                         "pqr"
                        };

    int i;
    char *t;

    t = names[3];
    names[3] = names[4];
    names[4] = t;

    for (i = 0; i <= 4; i++) {
        printf("%s\n", names[i]);
    }

    return 0;

}
