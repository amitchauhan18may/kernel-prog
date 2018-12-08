#include <stdio.h>

int main (void) {

    int i = 0;
    {
        XYZ:;
        auto int a = 20;
        //XYZ:;
        printf("%d\n", a);
        a++;
        i++;
    }

    if (i < 3)
        goto XYZ;

    return 0;
}
