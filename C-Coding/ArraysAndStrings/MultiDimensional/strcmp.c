#include <stdio.h>

int my_strcmp (char *str1, char *str2) {
    return (*str1 == *str2 && *str2 == '\0') ? 0
                                             : (*str1 == *str2) ?
                                               (my_strcmp(++str1, ++str2))
                                             : 1;
}

int main () {
    char str1[] = "amit";
    char *str2 = "ami";

    if(my_strcmp(str1, str2)) {
        printf("Strings are not same\n");
    } else {
        printf("Strings are same\n");
    }

    return 0;
}
