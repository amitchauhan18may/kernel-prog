#include <stdio.h>

static int g_val = 66;

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
