#include <stdio.h>
#include <string.h>

int main () {

    char arr[] = "HellO";
    int low_case = 0;
    int uppercase_case = 0;
    int i = -1;

    printf("Len: %d\n", strlen(arr));
    printf("arr: %s\n", arr);

    while (arr[i++] != '\0') {
        if (arr[i] >= 'A' && arr[i] <= 'Z')
            uppercase_case++;
        else if (arr[i] >= 'a' && arr[i] <= 'z')
            low_case++;
    }

    printf("low_case: %d | Upcase: %d\n", low_case, uppercase_case);

    return 0;
}
