#include <stdio.h>

typedef union u_data
{
        struct
        {
                int a;
                int b;
                char d;
                int c;
        };
                int elem[3];
}       my_data;

int     main(void)
{
        my_data data;

        data.a = 3;
        data.b = 5;
        data.c = -3;
        printf("%d, %d, %d\n", data.elem[0], data.elem[1], data.elem[3]);
}
