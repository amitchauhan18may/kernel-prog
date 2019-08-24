#include <stdio.h>
#include <stdlib.h>

int mystrupper (char *string) { 

    int i = -1;

    while (string[++i] != '\0') {
        if (string[i] >= 'a' && string[i] <= 'z')
            string[i] = string[i] - 32;
    }

}

int mystrlower (char *string) { 

    int i = -1;

    while (string[++i] != '\0') {
        if (string[i] >= 'A' && string[i] <= 'Z')
            string[i] = string[i] + 32;
    }

}

int main (void) {

    char arr[] = "amitchauhan";
 
    printf("Arr: %s\n", arr);
    
    mystrupper(arr);
    printf("Arr: %s\n", arr);

    mystrlower(arr);
    printf("Arr: %s\n", arr);

    return 0;

}
