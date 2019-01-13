#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _map_t_ {
    int code;
    char name[16];
    char *alias;
} _map_t_;


int main (void) {
    _map_t_ a, b, c;
    
    a.code = 100;
    snprintf(a.name, strlen("AmitChauhan") + 1, "AmitChauhan");
    char *alias = "Poo-Poo";
/* memcpy is not the right way to copy one structure to another*/
    memcpy(&b, &a, sizeof(b));

    c = a;

    return 0;
}
