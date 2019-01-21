#include <stdio.h>
#include <string.h>

char *fun () {
    static char arr[1024];
    return arr;
}

int main () {

    char *str = "geeksforgeeks";
    strcpy(fun(), str);
    str = fun();
    strcpy(str, "geeksquiz");

    printf("%s\n", fun());

    return 0;

}
