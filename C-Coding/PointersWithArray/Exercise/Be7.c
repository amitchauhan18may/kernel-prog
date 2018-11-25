#include <stdio.h>
/* Be7.c:8:7: error: assignment to expression with array type
     a = "coldwave";
 */

void func (char **p) {

    *p = "d";
}

int main () {

    char a[] = "Sunstroke";
    char *p = "Coldwave";

  //  a = "coldwave";
    p = "Sunstoke";
    func(&p);
    printf("a: %s | b: %s\n", a, p);

    return 0;
}


