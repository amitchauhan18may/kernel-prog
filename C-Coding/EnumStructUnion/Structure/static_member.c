#include <stdio.h>
/* Below error came on compilation
 * error: expected specifier-qualifier-list before ‘static’
 */
struct static_type {
    static int a;
};

int main () {
    printf("Testing static member of structure\n");
    return 0;
}
