#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char *p1 = "Raja";
    char *p2;
    p2 = strdup(p1);
 
    printf("Duplicated string is : %s\n", p2);
    free(p2);
    return 0;
}
