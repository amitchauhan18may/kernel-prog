#include <stdio.h>
#include <string.h>

int main (void) {

    char s[] = "Rendezvous!";

    printf("%d\n", *(s + strlen(s)));

    return 0;
}
