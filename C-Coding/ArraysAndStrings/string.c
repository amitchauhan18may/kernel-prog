#include <stdio.h>

int main () {
    /*Declaration and initialization of string*/
    char str[] = "Amit";
    char read_string[120];
    
    printf("str: %s\n", str);

    /*Read string from user*/
    printf("Please enter string\n");
    scanf("%[^\n]s", read_string);/*It can take input along with spaces*/
    printf("str: %s\n", read_string);

    return 0;
}
