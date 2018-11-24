#include <stdio.h>
#define ROW 3
#define COL 4

/*Function Returning Integer Pointer*/
int *func1(void) {

    printf("\nCalling Function: %s\n", __func__);

    int i, j;
    static int a[ROW][COL] = {
                               1, 2, 3, 4,
                               5, 6, 7, 8,
                               9, 10, 11, 12
                             };
    
    for (i = 0;i < ROW; i++) {
        for (j = 0; j < COL; j++) {
            printf("%d, ", a[i][j]);    
        }
        printf("\n");
    }
    
    return (int *)a;

}


/*Function Returning Pointer to Array of 4 integers*/
int (*func2())[COL] {

    printf("\nCalling Function: %s\n", __func__);

    int i, j;
    static int a[ROW][COL] = {
                               1, 2, 3, 4,
                               5, 6, 7, 8,
                               9, 10, 11, 12
                             };
    
    for (i = 0;i < ROW; i++) {
        for (j = 0; j < COL; j++) {
            printf("%d, ", a[i][j]);    
        }
        printf("\n");
    }
    
    return a;
}


/*Function Returning Pointer to 2-D Array of integers*/
int (*func3())[ROW][COL] {

    printf("\nCalling Function: %s\n", __func__);

    int i, j;
    static int a[ROW][COL] = {
                               1, 2, 3, 4,
                               5, 6, 7, 8,
                               9, 10, 11, 12
                             };
    
    for (i = 0;i < ROW; i++) {
        for (j = 0; j < COL; j++) {
            printf("%d, ", a[i][j]);    
        }
        printf("\n");
    }
    
    return (int (*)[ROW][COL])a;
}

int main (void) {

    int i, j;
    int *p;
    int (*q)[COL];
    int (*a)[COL];
    int (*r)[ROW][COL];

    p = func1();

    printf("\nCalling Function: %s\n", __func__);

    for (i = 0;i < ROW; i++) {
        for (j = 0;j < COL; j++) {
            printf("%d, ", *(p + i*COL +j));    
        }
        printf("\n");
    }

    q = func2();

    printf("\nCalling Function: %s\n", __func__);

    for (i = 0;i < ROW; i++) {
        a = q + i;

        for (j = 0;j < COL; j++) {
            printf("%d, ", *(*a + j));
        }
        printf("\n");
    }

    r = func3();

    printf("\nCalling Function: %s\n", __func__);
    
    for (i = 0;i < ROW; i++) {
        for (j = 0;j < COL; j++) {
            printf("%d, ", (*r)[i][j]);    
        }
        printf("\n");
    }

    return 0;

}
