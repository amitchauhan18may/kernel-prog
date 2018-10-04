#include <stdio.h>
/* This method cannot be applied if strings are stored using character arrays */
void swap (char **str1, char **str2) {
    char *temp = *str1;
    *str1 = *str2;
    *str2 = temp;
    return;
}

int main () {
    char *str2 = "Amit";
    char *str1 = "Chauhan";

    printf("Str1: %s, Str2: %s \n", str1, str2);
    
    swap(&str1, &str2);

    printf("Str1: %s, Str2: %s \n", str1, str2);

    return 0;
}
