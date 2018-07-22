#include <stdio.h>
#define FAIL 1

/*All enum constants must be unique in their scope.
 *For example, the following program fails in compilation*/

enum state {Pass, Fail};
#if FAIL
/*We can not repeat enum constants
 *as we have already used in 'enum state'*/
enum result {True, Fail};
#else
enum result {True, False};
#endif

int main () {

    return 0;
}
