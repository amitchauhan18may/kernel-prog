#include <stdio.h>
static int i;        //Declaring the variable i.
static int i=25;     //Initializing the variable.
static int i;        //Again declaring the variable i.
int main(){
    static int i;    //Again declaring the variable i.
    printf("%d\n",i);
    return 0;
}
