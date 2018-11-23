#include <stdio.h>

int main (void) {

    int a[2][3][2] = {
                       {
                         {2, 4},
                         {7, 8},
                         {3, 4}
                       },

                       {
                         {2, 2},
                         {2, 3},
                         {3, 4}
                       }
                     };

    printf("   a   = %p\n", a);
    printf("  *a   = %p\n", *a);
    printf(" **a   = %p\n", **a);
    printf("***a   = %d\n", ***a);
    printf("   a+1 = %p\n", a +1);
    printf("  *a+1 = %p\n", *a +1);
    printf(" **a+1 = %p\n", **a +1);
    printf("***a+1 = %d\n", ***a +1);

    return 0;

}
