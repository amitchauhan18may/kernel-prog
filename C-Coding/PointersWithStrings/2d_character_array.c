#include <stdio.h>
#include <string.h>
#define FOUND    1
#define NOTFOUND 0

int main (void) {

    char masterList[6][10] = {
                              "akshay",
                              "parag",
                              "raman",
                              "srinvas",
                              "gopal",
                              "rajesh"
                             };
    int i, flag, a;
    char name[35];

    printf("Please Enter Your Name\n");
    scanf("%s", name);

    flag = NOTFOUND;

    for (i = 0; i < 6; i++) {
        a = strcmp(&masterList[i][0], name);
        if (0 == a) {
            printf("Welcome! \n");
            flag = FOUND;
        }
    }

    if (flag == NOTFOUND) {
        printf("You are not allowed\n");
    }

    return 0;
}
