/* This method cannot be applied for strings
 * stored in read-only block of memory */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap (char *str1, char *str2) {
    char *temp = NULL;
    int len = 0;
    if (strlen(str1) > strlen(str2)) {
        len = strlen(str1);
        temp = (char *) malloc((strlen(str1)+1) * sizeof(char));
    } else {
        len = strlen(str2);
        temp = (char *) malloc((strlen(str2)+1) * sizeof(char));
    }
    strncpy(temp, str2, len);
    bzero(str2, strlen(str2));
    strncpy(str2, str1, len);
    strncpy(str1, temp, len);
    free(temp);

    return;
}

int main () {
    char str1[] = "Amit";
    char str2[] = "Chauhan";

    printf("Str1 : %s, Str2 : %s\n", str1, str2);

    swap(str1, str2);

    printf("Str1 : %s, Str2 : %s\n", str1, str2);
    return 0;
}
