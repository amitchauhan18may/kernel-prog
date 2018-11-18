#include <stdio.h>

void display (int *val) {
    printf("%d\n", *val);
    return;
}

void disp (int *arr, int element) {
    int i = 0;

    while (i < element) {
        printf("%d\n", *(arr+i));
        i++;
    }
}

int main () {
    int i;
    int arr[] = {1, 2, 3, 4, 5};

    disp(arr, 5); // or disp(&arr[0], 5)

//    for (i = 0; i < 5; i++) {
//        display(&arr[i]);
//    }

    return 0;
} 
