#include <stdio.h>

int main (void) {

    int i = 5;
    int j = ++i + ++i + ++i;
/*Below statement will give error L value required*/
//    int j = ++i+++i+++i;

    printf("i = %d | j = %d\n", i, j);

    return 0;

}
