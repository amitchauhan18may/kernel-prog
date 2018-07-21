#include <stdio.h>

/*Declaration of global variable*/
extern int g_var;
int g_var3;
void printGlobalVariable (void) {
    printf("[Function:%s] Global Variable value g_var: %d\n", __func__, g_var);
    g_var3 = 35;
    printf("[Function:%s] Global Variable value g_var3: %d\n", __func__, g_var3);
    return;
}
