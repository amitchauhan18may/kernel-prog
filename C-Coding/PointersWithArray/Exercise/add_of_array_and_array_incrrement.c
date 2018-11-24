#include <stdio.h>
/*
 * arr  :  0x7ffe56b369d0 | &arr  : 0x7ffe56b369d0
 * arr+1:  0x7ffe56b369d4 | &arr+1: 0x7ffe56b369e0
 *         Diff: 4-byte             Diff: 16-byte
 * 
 * arr2:   0x7ffe56b369e0 | &arr2:   0x7ffe56b369e0
 * arr2+1: 0x7ffe56b369f0 | &arr2+1: 0x7ffe56b36a10
 *         Diff: 16-byte             Diff: 48-byte 
 * 
 * arr3:   0x7ffe56b36a10 | &arr3:   0x7ffe56b36a10
 * arr3+1: 0x7ffe56b36a40 | &arr3+1: 0x7ffe56b36a70
 *         Diff: 48-byte             Diff: 96-byte
 */


int main (void) {

    int arr[] = {10, 20, 30, 40};

    int arr2[][4] = {
                  1, 2, 3, 4,
                  5, 6, 7, 8,
                  9, 10, 11, 12,
                 };

    int arr3[][3][4]={
                   {
                    1, 2, 3, 4,
                    5, 6, 7, 8,
                    9, 10, 11, 12,
                   },
                   {
                    1, 2, 3, 4,
                    5, 6, 7, 8,
                    9, 10, 11, 12,
                   }
                 };

    printf("arr  :  %p | &arr  : %p\n", arr, &arr);
    printf("arr+1:  %p | &arr+1: %p\n", arr+1, &arr+1);
    printf("\n\n");
    printf("arr2:   %p | &arr2:   %p\n", arr2, &arr2);
    printf("arr2+1: %p | &arr2+1: %p\n", arr2+1, &arr2+1);
    printf("\n\n");
    printf("arr3:   %p | &arr3:   %p\n", arr3, &arr3);
    printf("arr3+1: %p | &arr3+1: %p\n", arr3+1, &arr3+1);

    return 0;
}
