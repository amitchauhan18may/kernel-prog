#include <stdio.h>
#include <stdlib.h>

_Noreturn void view () {
#if 0
    return 12;
#endif
    printf("BYE BYE");
}

int main () {
    view();

    return 0;
}
