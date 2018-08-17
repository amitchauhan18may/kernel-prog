#include <stdio.h>

#if 0
int test_strinf_func (char *string) {
#else
int test_strinf_func (char string []) {
#endif
    printf("String: %s\n", string);
}

int main () {
    char string[] = "Amit Chauhan";
    test_strinf_func(string);

    return 0;
}
