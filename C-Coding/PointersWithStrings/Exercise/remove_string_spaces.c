#include <stdio.h>
#include <stdlib.h>

void remove_spaces (char *str) {

    int count = 0;
    int i = 0;

    for (i = 0; str[i]; i++)
        if (str[i] != ' ')
            str[count++] = str[i];

    str[count] = '\0';

    return;
}


int main (void) {

    char arr[] = "a m i t j i";

    printf("arr: %s\n", arr);

    remove_spaces(arr);

    printf("arr: %s\n", arr);

    return 0;
}
