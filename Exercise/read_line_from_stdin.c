#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int i = 4;
    double d = 4.0;
    char s[] = "HackerRank ";
    int j, len, c = 0;
    double dd;
    char str[100];
    char strc[150];

    scanf("%d", &j);
    scanf("%lf", &dd);
    while ((getchar()) != '\n'); 
    while(1)
    {
        char ch = getchar();
        if(ch != '!')
            str[c++] = ch;
        else
            break;
    }
 
    strncpy(strc, s, strlen(s));
    strcat(strc, str);
    len = strlen(strc);
    strc[len] = '!';

    printf("%d\n", i+j);
    printf("%0.1f\n", d + dd);
    printf("%s", strc);
    
    return 0;
}
