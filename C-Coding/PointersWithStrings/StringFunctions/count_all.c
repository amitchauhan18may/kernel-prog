#include <stdio.h>
#include <string.h>

int main () {

    char arr[] = "HellO S|r@123";
    int alphabate = 0;
    int digits = 0;
    int spaces = 0;
    int spacial_char = 0;
    int i = 0;

    printf("Len: %d\n", strlen(arr));
    printf("arr: %s\n", arr);

    while (arr[i] != '\0') {
        if ((arr[i] >= 'A' && arr[i] <= 'Z') ||
             (arr[i] >= 'a' && arr[i] <= 'z'))
            alphabate++;
        else if (arr[i] >= '0' && arr[i] <= '9')
            digits++;
        else if (arr[i] == ' ')
            spaces++;
        else
            spacial_char++;
        i++;
    }

    printf("alphabate: %d\n", alphabate);
    printf("digits: %d\n", digits);
    printf("spaces: %d\n", spaces);
    printf("spacial_char: %d\n", spacial_char);

    return 0;
}
