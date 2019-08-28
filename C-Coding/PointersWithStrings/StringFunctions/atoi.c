#include <stdio.h>
#include <string.h>

int main () {
    int res = 0;
    char *str = "+12345";
    int i = 0;
    int sign = 1;

    if (str[i] == '-' || str[i] == '+') {
        sign = 1 - 2 * (str[i] == '-');
        i++;
    }

    while (str[i] >= '0' && str[i] <= '9') {
        res = 10 * res + str[i] - '0';
        i++;
    }

    printf("Res: %d\n", sign * res);

    return 0;
}
