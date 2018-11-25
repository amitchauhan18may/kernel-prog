#include <stdio.h>
#include <string.h>

int main (void) {

    char str1[20] = "Bamboozled";
    char str2[] = "Chap";
    char str3[20];

    int l, k;

    l = strlen(str1);

    printf("Length: %d\n", l);

    strcpy(str3, str1);
    printf("After copying string str3: %s\n", str3);

    k = strcmp(str1, str2);
    printf("On comparing str1 and str2, k =%d\n", k);

    k = strcmp(str3, str1);
    printf("On comparing str3 and str1, k =%d\n", k);

    strcat(str1, str2);
    printf("On concatenaion str1 = %s\n", str1);

    return 0;
}
