#include <stdio.h>

//extern int i;
/*Below statement will give error
 *Previous declaration is present
 */
//static int i;
int i = 1;
i = 3;

int main (void) {

 //   i = 3;
    printf("%d\n", i);

    return 0;

}
