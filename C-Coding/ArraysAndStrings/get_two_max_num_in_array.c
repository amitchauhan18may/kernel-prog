#include <stdio.h>
#include <limits.h>

int main () {
    int a[] = {12, 1, 15, 2, 44, 8};
    int max1 = INT_MIN;
    int max2 = INT_MIN;
    int max3 = INT_MIN;
    int i = 0;
    int size_of_array = sizeof(a)/sizeof(a[0]);

    printf("length: %d\n", size_of_array);

    for (i = 0; i < size_of_array; i++) {
        if (a[i] > max1) {
            max3 = max2;
            max2 = max1;
            max1 = a[i];
        } else if (a[i] > max2) {
            max3 = max2;
            max2 = a[i];
        } else if (a[i] > max3) {
            max3 = a[i];
        }
    }


    printf("Max1: %d  | Max2: %d | Max3: %d\n", max1, max2, max3);
    return 0;

}
