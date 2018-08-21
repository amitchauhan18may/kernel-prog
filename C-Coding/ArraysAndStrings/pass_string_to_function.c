#include <stdio.h>

#if 0
int test_strinf_func (char *string) {
#else
/* Array parameters are always passed as pointers,
 * even when we use square brackets*/
int test_string_func (char string[]) {
#endif
    printf("sizeof(string) = %zu\n", sizeof(string));
    printf("String: %s\n", string);
}

int main () {
    char string[] = "Amit Chauhan";
    test_string_func(string);

    return 0;
}
