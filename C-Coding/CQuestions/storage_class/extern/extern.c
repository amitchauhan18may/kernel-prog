#include <stdio.h>
//extern int i = 9;
extern int i;
int i = 10;
extern int i;

void func(){
    //extern int i;
    //printf("Func:%d\n", i);
}

int main (void) {

    //extern int i = 9;
    extern int i;
    //i = 9;
    //int i = 9;
    printf("%d\n", i);
//    func();
    return 0;
}

//extern int i = 6;
//static int i = 6;
