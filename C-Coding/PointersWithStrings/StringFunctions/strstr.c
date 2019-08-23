#include <stdio.h>
#include <string.h>

int strstr_using_len (char *string, char *substring) {

    int string_len = strlen(string);
    int sub_string_len = strlen(substring);
    int i, j;

    for (i = 0; i < (string_len - sub_string_len); i++) {
        for (j = 0; j < sub_string_len; j++) {
            if (string[i+j] != substring[j])
                break;
        }
        
        if (j == sub_string_len) {
            return i;
        }
    }

    return -1;
}

int main (void) {

    char arr1[] = "AmitChauhan";
    char arr2[] = "jmit";

    int location = strstr_using_len(arr1, arr2);

    if (location != -1)
        printf("Substring found at : %d\n", location);
    else
        printf("Substring not found\n");

    return 0;
}
