#include <stdio.h>

const char *func () {
    return "Amit";
}

int main (void) {

    const char *p;

    p = func();

    printf("p: %s\n", p);
/* 
return_const_value_from_function.c:15:8: error: assignment of read-only location ‘*p’
     *p = 'R';
 */ 
//    *p = 'R';

    return 0;
}
