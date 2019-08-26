#include <stdio.h>
#include <string.h>

int main() {
    
    char arr[] = "bba";
    int len = strlen(arr);
    int i = 0;
    int j = len - 1;

    while (i < j) {
        if (arr[i++] != arr[j--]) {
            printf("string is not palindrom\n");
            return 1;
        }
    }

    printf("string is palindrom\n");

}

