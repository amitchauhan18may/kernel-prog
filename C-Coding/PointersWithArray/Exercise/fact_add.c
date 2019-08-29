#include <stdio.h>

int rec (int num) {

    if (num == 0)
        return 0;

    return num + rec(num - 1);
}

int main (void) {

    int num = 3;
//    int res = 0;
//
//    while (num != 0) {
//         res += num;
//         num = num - 1;
//    }
//
//    printf("Res: %d\n", res);
    printf("Res: %d\n", rec(num));

}
