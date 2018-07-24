#include <stdio.h>

struct test {
    unsigned int a: 5;
    unsigned int b: 5;
    unsigned int c;
};

int main () {
    struct test check_address = {
        .a = 10,
        .b = 20,
        .c = 30
    };
/*error: cannot take address of bit-field ‘a’*/
    //printf("Address of .a= %lu\n", &check_address.a);
/*error: cannot take address of bit-field ‘b’*/
    //printf("Address of .b= %lu\n", &check_address.b);
    printf("Address of .c= %p\n", &check_address.c);

    return 0;
}
