#include <stdio.h>
#include <string.h>

int main () {

    char arr[] = "HellO";
    int i = -1;

    printf("Len: %d\n", strlen(arr));
    printf("arr: %s\n", arr);

    while (arr[i++] != '\0') {
        if (arr[i] >= 'A' && arr[i] <= 'Z')
            arr[i] = arr[i] + 32;
        else if (arr[i] >= 'a' && arr[i] <= 'z')
            arr[i] = arr[i] - 32;
    }

    printf("arr: %s\n", arr);

    return 0;
}
