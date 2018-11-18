#include <stdio.h>

int main () {
    int *p1, i = 25;
    void *p2;

    p1 = &i;
    p2 = &i;

    p1 = p2;
    p2 = p1;
/* Above won't give any warning or error 
 * untill we are not going to derefernce it
 */
    //printf("Value: %p\n", *p2);

    return 0;
}
