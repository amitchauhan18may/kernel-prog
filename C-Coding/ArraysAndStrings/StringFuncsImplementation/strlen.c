#include <stdio.h>
#include <stdlib.h>

int my_strlen (const char *str) {

    int i = 0;
    int count = 0;

    while (str[i++] != '\0') {
        count += 1;
    }

    return count;

}

int main (void) {

    //char arr[100] = {0};
    char *arr = "amit chauhan";
    int length = 0;

    printf("Please enter the string\n");
    //scanf("%s", arr);

    length = my_strlen(arr);

    printf("Length of enterd string: %d\n", length);

    return 0;

}
