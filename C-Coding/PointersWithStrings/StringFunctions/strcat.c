#include <stdio.h>
#include <string.h>
#define MAXSIZE 100
int mystrcat (char *arr, char *arr1) {

    int len = strlen(arr) + strlen(arr1);
    int i = 0;

    if (len > MAXSIZE)
        return -1;

    len = strlen(arr);

    for (i= 0; i < strlen(arr1); i++) {
        arr[len+i] = arr1[i];
    }

    arr[len+i] = '\0';

    return 0;

}

int main (void) {

    char arr[100] = "Amit";
    char arr2[100] = "Chauhan";

    printf("arr: %s\n", arr);

    if(!mystrcat(arr, arr2))
        printf("arr: %s\n", arr);

    return 0;

}
