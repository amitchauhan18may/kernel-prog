#include <stdio.h>

/*Declaring and initializing global variable*/
extern int g_var;

/*Global Without extern keyword*/
static int g_var2 = 20;

int main () {
    auto int a_var = 30;
    register char b = 'R';

    printf("Demonstrating Different Storage Classes\n");

    printf("Auto Storage Class Variable:      a_var:%d\n", a_var);
    printf("Register Storage Class Variable:  b    :%c\n", b);

    printf("Before Change Global Storage Class Variables:   g_var:%d g_var2:%d\n", g_var, g_var2);
    g_var = 1;
    g_var2 = 2;

    printf("After Change Global Storage Class Variables:   g_var:%d g_var2:%d\n", g_var, g_var2);
    {

    }

    return 0;
}
