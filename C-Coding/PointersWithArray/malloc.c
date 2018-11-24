#include <stdio.h>
#include <stdlib.h>

int main () {

    int number, avg, i, *ptr, sum = 0;

    printf("Enter the nubmer of Studentes\n");
    scanf("%d", &number);

    ptr = (int *) malloc(number * sizeof(int));
    if (NULL == ptr) {
        printf("Failed to allocate memory\n");
        return -1;
    }

    for (i = 0;i < number; i++) {
        scanf("%d", (ptr+i));
    }

    for (i = 0;i < number; i++) {
        sum += *(ptr+i);
    }

    avg = sum/number;

    printf("Avrage Marks: %d\n", avg);

    return 0;

}
