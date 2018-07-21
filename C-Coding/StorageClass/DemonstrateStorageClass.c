#include <stdio.h>
void printGlobalVariable(void);
 
/*Declaration of global variable
This can be declare many times
 but can be defuned only once*/
int g_var;

/*Global Without extern keyword*/
int g_var2 = 20;

int main () {
    auto int a_var = 30;
    register char b = 'R';
    int static_test = 3;
    static int s_var = 5;
    /*Here we are demonstrating the extern within the block*/    
    extern int g_var3;

    printf("Demonstrating Different Storage Classes\n\n");
    printf("[File:%s]Global g_var3: %d\n", __FILE__, g_var3);

    printf("Auto Storage Class Variable:      a_var:%d\n", a_var);
    printf("Register Storage Class Variable:  b    :%c\n", b);

    printGlobalVariable();

    printf("Before Change Global Storage Class Variables:   g_var:%d g_var2:%d\n", g_var, g_var2);
    g_var = 1;
    g_var2 = 2;

    printf("After Change Global Storage Class Variables:   g_var:%d g_var2:%d\n", g_var, g_var2);
   
    printf("Static Storage class\n");
    while (static_test > 0) {
        printf("Static s_var: %d\n", s_var);
        s_var++;
        static_test--;
    }

    printGlobalVariable();
    return 0;
}
