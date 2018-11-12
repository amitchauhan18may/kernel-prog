/*
 nested_function.c: In function ‘main’:
 nested_function.c:14:5: warning: implicit declaration of function ‘func2’; did you mean ‘func’? [-Wimplicit-function-declaration]
      func2();
      ^~~~~
      func
 /tmp/cc31JZdN.o: In function `main':
 nested_function.c:(.text+0x31): undefined reference to `func2'
 collect2: error: ld returned 1 exit status
 <builtin>: recipe for target 'nested_function' failed
 make: *** [nested_function] Error 1

*/

#include <stdio.h>
#include <stdlib.h>

int main () {
    printf("Inside main\n");

    int func () {
        printf("Inside func\n");
        int func2 () {
            printf("Inside func2\n");
        }
    }

    func2();

    return 0;
}
