#include <stdio.h>

int main () {
#if 1
/*error: array type has incomplete element type ‘int[][2]’*/
    int a[][][2] = { {{1, 2}, {3, 4}},
#else
    int a[][2][2] = { {{1, 2}, {3, 4}},
#endif
                     {{5, 6}, {7, 8}}
                   };
    printf("Sizeof: %zu\n", sizeof a);
    return 0;
}
