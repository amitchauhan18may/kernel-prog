/* This method cannot be applied for strings
 * stored in read-only block of memory */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap (char *str1, char *str2) {
    char *temp = (char *) malloc((strlen(str1)+1) * sizeof(char));
    strcpy(temp, str1);
    strcpy(str1, str2);
    strcpy(str2, temp);
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
