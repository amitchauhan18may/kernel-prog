#include <stdio.h>
/* Output:
 * Before: 0x7ffcb1af4d04 0x7ffcb1af4d04
 * After:  0x7ffcb1af4d08 0x7ffcb1af4d05
 *
 * void pointer will increment by 1-byte
 */
int main () {
    int a = 10, *j;
    void *k;

    j = k = &a;
    
    printf("Before: %p %p\n", j, k);

    j++;
    k++;

    printf("After:  %p %p\n", j, k);

    return 0;
}
