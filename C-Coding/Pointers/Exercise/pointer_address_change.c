#include <stdio.h>
/*error: lvalue required as left operand of assignment*/
int main () {

    int i = 10;

    printf("Value : %d | Address: %p\n", i, &i);
    
    &i = 7200;
    printf("Value : %d | Address: %p\n", i, &i);

    return 0;
}
