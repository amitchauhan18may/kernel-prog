#include <stdio.h>
#include <stdlib.h>

/* NULL - 0x00000000 or 0x00000000'00000000 (32 vs 64 bit)
 * NUL  - 0x00 or 0x0000 (ascii vs 2byte unicode)
 * '0'  - 0x20 (integer character constant)
 *  0   - 0x30 (48 in Decimal)
 */


int main (void) {

    printf("Size-of NUL: %ld\n", sizeof('\0'));
    return 0;

}
