#include <stdio.h>

int main () {
    int arr[] = {10, 20, 30};
    int x = 5;
    int *ptr = &x;
    arr = &x;/*error: assignment to expression with array type*/
    return 0;
}
