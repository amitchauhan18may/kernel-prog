#include <stdio.h>

struct cl {
    int a;
    int b;
};

int print_structure (struct cl obj) {
    printf("obj.a = %d obj.b = %d\n", obj.a, obj.b);
    return 0;
}

int main () {
    print_structure((struct cl){1, 2});
    return 0;
}
