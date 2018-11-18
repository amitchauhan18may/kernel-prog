#include <stdio.h>

void disp(int *);

int main () {
    int i;
    int marks[] = {1, 2, 3, 4, 5, 6, 7};

    for (i = 0;i < 7; i++) {
        disp(&marks[i]);
    }

    return 0;
}

void show (int **val) {
    printf("%d\n", **val);
}

void disp (int *n) {
    show(&n);
}
