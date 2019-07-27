#include <stdio.h>

extern int i;
extern int j;

void sum (void) {
    
    int s = i + j;
    printf("%d\n", s);
    
    return;
}
