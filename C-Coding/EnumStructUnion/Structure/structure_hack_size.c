#include <stdio.h>

struct struct_a {
    int a;
    int b;
    char arr[];
};

/* In gcc, when we create an array of zero length,
 * it is considered as array of incomplete type that’s why
 * gcc reports its size as “0” bytes.*/
int main () {
    struct struct_a s_a;
    printf("struct_a {\n"
                "\tint a;\n"
                "\tint b;\n"
                "\tchar arr[0];\n"
           "}\n""Size of struct_a = %lu\n", sizeof(s_a));
    return 0;
}
