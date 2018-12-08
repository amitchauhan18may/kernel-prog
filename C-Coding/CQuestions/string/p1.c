#include<dos.h>
#include<stdio.h>
int main(){
union REGS i,o;
i.h.ah=2;   //positioning the cursor 
i.h.bh=0;
i.h.dh=30;   
i.h.dl=45;
int86(0x10,&i,&o);
printf("World");
return 0;
}

