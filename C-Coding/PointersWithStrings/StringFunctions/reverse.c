#include <stdio.h>
#include <string.h>

char *reverse (char *str) {

    int len = strlen(str);
    int i = 0, j = len - 1;
    char temp;

    printf("%s: len: %d\n", __func__, len);

    while (i < j) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        i++;
        j--;
    }

    printf("%s: %s\n", __func__, str);

    return str;

}

int main (void) {

    char arr[] = "abcde";

    printf("%s: %s\n", __func__, arr);

    printf("%s: %s\n", __func__, reverse(arr));


}
