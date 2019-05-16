#include<stdio.h>
int main(){
    int i=0;
    {
         XYZ:;/*This is defined din different block*/
         auto int a=20;
         printf("%d",a);
         a++;
         i++;
    }
    if (i<3)
         goto xyz;/*error: label ‘xyz’ used but not defined*/
    return 0;
}
