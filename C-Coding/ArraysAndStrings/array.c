#include <stdio.h>

int main () {
/*Array declaration*/
    int arr[10];

/*Array declaration with initialization*/
    int arr1[3] = {0, 1, 2};
    int arr2[]  = {3, 4, 5};
    int arr3[3] = {6, 7};

    printf("Initialization: int arr1[3] = {0, 1, 2}\n");
    printf("arr1[0] = %d arr1[1] = %d arr1[2] = %d\n", arr1[0], arr1[1], arr1[2]);
    printf("\nInitialization: int arr2[]  = {3, 4, 5};\n");
    printf("arr2[0] = %d arr2[1] = %d arr2[2] = %d\n", arr2[0], arr2[1], arr2[2]);
    printf("\nInitialization: int arr2[]  = {6, 7};\n");
    printf("arr3[0] = %d arr3[1] = %d arr3[2] = %d\n", arr3[0], arr3[1], arr3[2]);
    return 0;
}
