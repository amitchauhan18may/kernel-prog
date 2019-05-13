#include <stdio.h>
#include <stdlib.h>

int arr[5] = {3, 7, 9, 1, 2};

void swap (int *a, int *b) {

    int swp = -1;
    swp = *a;
    *a  = *b;
    *b  = swp;

    return;

}

int partition (int arr[], int start, int end) {

    int pivot     = arr[end];
    int partition = start;
    int i         = 0;

    for (i = 0; i < end - 1; i++) {
        if (arr[i] < pivot) {
            partition++;
            swap(&arr[i], &arr[partition]);
        }
    }

    swap(&arr[partition], &arr[end]);

    return partition;

}

int main (void) {

    int i = 0;
    int pindex = partition (arr, 0, 7);

    printf("%d\n", arr[pindex]);

    for (i = 0; i < 5; i++) {
        printf("Arr[%d]: %d\n", i, arr[i]);
    }

    return 0;

}
