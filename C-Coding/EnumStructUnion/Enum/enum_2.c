#include <stdio.h>

enum day {sunday=1, tuesday, wednesday, thursday, friday, saturday};

int main () {
    enum day d = thursday;
    printf("Day no: %d\n", d);
    printf("Size of Enum day: %ld\n", sizeof(d));
    return 0;
}
