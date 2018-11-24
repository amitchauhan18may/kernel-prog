#include <stdio.h>

int main (void) {

    char a[] = "Visual C++";
    char *b = "Visual C++";

    printf("Sizeof(a): %ld | Sizeof(b): %ld\n", sizeof(a), sizeof(b));
    printf("Sizeof(*a): %ld | Sizeof(*b): %ld\n", sizeof(*a), sizeof(*b));
    return 0;
}
