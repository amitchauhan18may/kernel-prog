#include <stdio.h>
#include <stdlib.h>

/* NULL or pointer - 0x00000000 or 0x00000000'00000000 (32 vs 64 bit)
 * NUL or '\0'  - 0x00 or 0x0000 (ascii vs 2byte unicode)
 * '0' or space - 0x20 (integer character constant space)
 *  0   - 0x30 (48 in Decimal)
 */


int main (void) {

    printf("Size-of NUL: %ld\n", sizeof('\0'));

    printf("space=%c\n", 0);
    printf("decimal of 0 = %d: %c\n", 0x30, 0x30);
    return 0;

}
