#include <stdio.h>
struct scope {
    struct {
        char alpha;
        int num;
    };
};

struct scope1 {
    union {
        char alpha;
        int num;
    };
};

int main () {
    struct scope x;
    struct scope1 x1;
    x.num = 5;
    x1.num = 5;

    printf("x.num = %d \nx1.num = %d\n", x.num, x1.num);
    return 0;
}
