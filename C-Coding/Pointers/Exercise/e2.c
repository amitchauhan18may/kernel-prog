#include <stdio.h>

int main () {

    char c, *cc;
    int i;
    long l;
    float f;

    c = 'z';
    i = 15;
    l = 77777;
    f = 3.14;

    cc =&c;
    printf("c = %c | cc = %p\n", *cc, cc);

    cc = &i;
    printf("i = %d | cc = %p\n", *cc, cc);
    
    cc = &l;
    printf("l = %ld:%d | cc = %p\n", *cc, *cc, cc);
    
    cc = &f;
    printf("f = %f | cc = %p\n", *cc, cc);
    return 0;
}
