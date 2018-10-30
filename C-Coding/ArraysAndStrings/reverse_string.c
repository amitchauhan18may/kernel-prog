#include <stdio.h>
#include <string.h>
char* reverse_string (char* reverse) {
    int len = strlen(reverse);
    int i, j;
    char temp;
    for (i = 0, j = len -1; i < j; i++, j--) {
        temp = reverse[i];
        reverse[i] = reverse[j];
        reverse[j] = temp;
    }

    printf("string: %s\n", reverse);
    return reverse;
}

int main () {
    char string[] = "abcd";
    reverse_string(string);
    return 0;
}
