#include <stdio.h>

int main () {
    int arr[] = {10, 20, 30, 40, 50};
    int *ptr = arr;
    printf("Value At ptr = %d\n", *ptr);
    printf("Value At *(ptr+0) = %d\n", *(ptr+0));
    printf("Value At *(ptr+1) = %d\n", *(ptr+1));
    printf("Value At ptr[1] = %d\n", ptr[1]);
    printf("Value At arr[1] = %d\n", arr[1]);

    return 0;
}
