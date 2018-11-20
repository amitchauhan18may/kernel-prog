#include <stdio.h>
/* error: too many arguments to function ‘main’
 * Below program will work fine if we remove void from main
 */
int main (void) {
    static int i = 5;

    if (--i) {
        printf("%d\n", i);
        main(10);
    }
}
