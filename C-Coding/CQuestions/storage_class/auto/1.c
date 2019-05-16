#include<stdio.h>
int main(){
    int a=0;
    {
         int a=10;
         printf("%d",a);
         a++;
         {
             a=20;
         }
         {
             printf(" %d",a);/*Always look for nearest if variable not in block*/
             int a=30; {a++;}
             printf(" %d",a++);
         }
         printf(" %d",a++);
    }
    printf(" %d",a);
    return 0;
}
