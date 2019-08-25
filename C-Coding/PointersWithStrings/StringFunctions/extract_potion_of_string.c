#include <stdio.h>

int get_portion (char *string, char *portion, int from, int to) {

    int string_len = 0;
    int i = 0;

    while (string[i++] != '\0')
        string_len++;

    if (to > string_len)
        return -1;

    for (i = 0; from <= to; i++, from++)
        portion[i] = string[from]; 

    return 0;

}

int main (void) {

    char string[] = "I am the best";
    char portion[100] = {0};
    int from = 3, to = 7;

    printf("string: %s\n", string);
    printf("Range: %d to %d\n", from, to);

    if (!get_portion(string, portion, from, to))
        printf("portion: %s\n", portion);
    else
        printf("portion is not in range\n");

    return 0;

}
