#include <stdio.h>

void display (int *val) {
    printf("%d\n", *val);
    return;
}

int main () {
    int i;
    int arr[] = {1, 2, 3, 4, 5};

    for (i = 0; i < 5; i++) {
        display(&arr[i]);
    }

    return 0;
} 
