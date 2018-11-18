#include <stdio.h>
/*error: invalid operands to binary * (have ‘int *’ and ‘int’)*/
int main () {

    int *i, *j;
    j = i * 2;

    printf("j = %p\n", j);

    return 0;
}
