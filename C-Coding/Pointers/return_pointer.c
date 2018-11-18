#include <stdio.h>

int *func (void) {
/* If we won't declare as static,
 * it will give segmentation fault
 */
    static int i = 25;
   
    printf("Func() Address of i: %p\n", &i);
    return (&i);
}


int main () {
    int *i;

    i = func();

    printf("Main() Address of i: %p\n", i);
    printf("Value: %d\n", *i);

    return 0;
}
