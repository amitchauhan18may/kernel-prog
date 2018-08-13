#include <stdio.h>

int main () {
    int arr[2] = {1, 2};
/*No index out of bound checking*/
    printf("%d %d\n", arr[0], arr[-2]);
    return 0;
}
