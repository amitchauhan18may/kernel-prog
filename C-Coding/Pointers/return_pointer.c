#include <stdio.h>

extern int j = 0;
int *func (void) {
/* If we won't declare as static,
 * it will give segmentation fault
 */
    static int i = 25;
    printf("Func() Address of i: %p : %d\n", &i, i);
    return (&i);
}


int main () {
    int *i;

    i = func();
    *i = 2;
    func();
    printf("Main() Address of i: %p\n", i);
    printf("Value: %d\n", *i);

    return 0;
}
