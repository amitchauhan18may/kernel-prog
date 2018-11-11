#include <stdio.h>
#include <stdlib.h>

/* implicit_return_type.c:4:1: warning: return type defaults to ‘int’ [-Wimplicit-int]
   function (int x) {
 */

function (int x) {
    return x * x;
}

int main () {
    printf("Output: %d\n", function(5));

    return 0;
}
