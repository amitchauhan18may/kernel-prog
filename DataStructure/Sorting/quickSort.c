#include <stdio.h>
#include <stdlib.h>

int arr[5] = {3, 7, 9, 1, 2};

void print_array (int arr[], int size) {

    int i = 0;

    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    
    printf("\n");


}

void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

//void swap (int *a, int *b) {
//
//    int swp = *a;
//    *a  = *b;
//    *b  = swp;
//
//    return;
//
//}

int partition (int arr[], int start, int end) {

    int pivot     = arr[end];
    int partition = start;
    int i         = 0;

    for (i = start; i < end - 1; i++) {
        if (arr[i] <= pivot) {
            swap(&arr[i], &arr[partition]);
            partition++;
        }
    }

    swap(&arr[partition], &arr[end]);

    return partition;

}


void quicksort (int arr[], int start, int end)
{
    if (start < end) {
        int pindex = partition (arr, 0, end);
        quicksort (arr, start, pindex - 1);
        quicksort (arr, pindex + 1, end);
    }

    return;
}

int main (void) {

    int arr[] = {10, 80, 30, 90, 40, 50, 70};

    int end = sizeof(arr)/sizeof(arr[0]);

    print_array(arr, end);

    quicksort(arr, 0, end-1);
    
    printf("Sorted Array\n");
    print_array(arr, end);

    return 0;

}
