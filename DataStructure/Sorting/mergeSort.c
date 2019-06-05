#include <stdio.h>

void print_array (int *arr, int size) {

    int i = 0;

    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);

    printf("\n");

    return;
}


void merge_left_and_right (int arr[], int left, int mid, int right) {

    printf("[%s] : left: %d | mid: %d | right : %d\n", __func__, left,
            mid, right);

    int i;
    int j;
    int k;
    int l_array_len = mid - left + 1;
    int r_array_len = right - mid;
    printf("l: %d r: %d\n", l_array_len, r_array_len);
    int l_array[l_array_len];
    int r_array[r_array_len];

    for (i = 0; i < l_array_len; i++)
        l_array[i] = arr[left + i];

    for (j = 0; j < r_array_len; j++)
        r_array[j] = arr[mid + 1 + j];

    i = 0;
    j = 0;
    k = left;

    while (i < l_array_len && j < r_array_len) {
        
        if (l_array[i] <= r_array[j]) {
            arr[k] = l_array[i];
            i++;
        } else {
            arr[k] = r_array[j];
            j++;
        }

        k++;
    }

    while (i < l_array_len) {
        arr[k] = l_array[i];
        i++;
        k++;
    }

    while (j < r_array_len) {
        arr[k] = r_array[j];
        j++;
        k++;
    }

    return;

}


void merge_sort (int arr[], int left, int right) {

    if (left < right) {
    
        int mid = left + (right - left) / 2;

        //printf("Sorting Left\n");
        merge_sort(arr, left, mid);
        //printf("Sorting right\n");
        merge_sort(arr, mid + 1, right);

        merge_left_and_right(arr, left, mid, right);
    }

    return;

}


int main (void) {

    int arr[] = {2, 1, 3, 5, 6, 7};

    int array_size = sizeof(arr)/sizeof(arr[0]);
    printf("SIZE: %d\n", array_size);
    printf("Array Before Sorting\n");
    print_array(arr, array_size);

    merge_sort(arr, 0, array_size-1);

    printf("Array After Sorting\n");
    print_array(arr, array_size);

    return 0;
}
