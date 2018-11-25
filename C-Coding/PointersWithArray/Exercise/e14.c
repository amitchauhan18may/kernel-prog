#include <stdio.h>

void change (int *b) {
    int i;

    for (i = 0;i < 5; i++) {
        *b = *b + 1;
        b++;
    }

}

int main (void) {

    int a[5] = {2,3,4,5,6};
    int i;
    
    change(a);

    for (i = 4;i >= 0; i--) {
        printf("%d ", a[i]);
    }
    

    return 0;
}
