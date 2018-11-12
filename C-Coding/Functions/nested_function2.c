#include <stdio.h>
#include <stdlib.h>

int main () {
    printf("Inside main\n");
    auto int func2();
    func2();
    int func () {
        printf("Inside func\n");
    }

    int func2 () {
        printf("Inside func2\n");
    }

    return 0;
}
