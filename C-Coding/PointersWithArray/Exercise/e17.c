#include <stdio.h>

int main () {

    int arr[] = {0, 1, 2, 3, 4};
    int i, *ptr;

    //for (ptr = arr+4, i = 0;i <= 4; i++) {
    //    printf("%d ", ptr[-i]);
    //}

    for (ptr = arr+4; ptr >= arr; ptr--) {
        printf("%d ", arr[ptr - arr]);
    }

    return 0;
}
