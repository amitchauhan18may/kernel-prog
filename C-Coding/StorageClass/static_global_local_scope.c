#include <stdio.h>
/* On commenting below statement compiler will throwh below error
 * static_global_local_scope.c:21:26: error: ‘g_val’ undeclared (first use in this function)
     printf("func: %d\n", g_val);
 *
 */
//static int g_val = 66;

void func(void);

int main (void) {

    static int g_val = 5;
    while (--g_val) {
        func();
        printf("%d\n", g_val);
    }

    return 0;

}

void func (void) {

    printf("func: %d\n", g_val);
    return;

}
