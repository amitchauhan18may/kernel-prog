#include <stdio.h>
#define SET 2
#define ROW 3
#define COL 4

int *func1 (void) {

    printf("\nCalling Function: %s\n", __func__);

    int i, j, k;
    static int a[SET][ROW][COL] = {
                                    {
                                      1, 2, 3, 4,
                                      5, 6, 7, 8,
                                      9, 10, 11, 12
                                    },
                                    {
                                      11, 22, 33, 44,
                                      55, 66, 77, 88,
                                      99, 110, 111, 112
                                    }
                                  };

    for (i = 0;i < SET; i++) {
        for (j = 0; j < ROW; j++) {
            for (k = 0; k < COL; k++) {
                printf("%d, ", a[i][j][k]);
            }
            printf("\n");
        }
        printf("\n");
    }

    return (int *)a;

}


int (*func2(void))[COL] {

    printf("\nCalling Function: %s\n", __func__);

    int i, j, k;
    static int a[SET][ROW][COL] = {
                                    {
                                      1, 2, 3, 4,
                                      5, 6, 7, 8,
                                      9, 10, 11, 12
                                    },
                                    {
                                      11, 22, 33, 44,
                                      55, 66, 77, 88,
                                      99, 110, 111, 112
                                    }
                                  };

    for (i = 0;i < SET; i++) {
        for (j = 0; j < ROW; j++) {
            for (k = 0; k < COL; k++) {
                printf("%d, ", a[i][j][k]);
            }
            printf("\n");
        }
        printf("\n");
    }

    return (int (*)[COL])a;

}


int (*func3(void))[ROW][COL] {

    printf("\nCalling Function: %s\n", __func__);

    int i, j, k;
    static int a[SET][ROW][COL] = {
                                    {
                                      1, 2, 3, 4,
                                      5, 6, 7, 8,
                                      9, 10, 11, 12
                                    },
                                    {
                                      11, 22, 33, 44,
                                      55, 66, 77, 88,
                                      99, 110, 111, 112
                                    }
                                  };

    for (i = 0;i < SET; i++) {
        for (j = 0; j < ROW; j++) {
            for (k = 0; k < COL; k++) {
                printf("%d, ", a[i][j][k]);
            }
            printf("\n");
        }
        printf("\n");
    }

    return (int (*)[ROW][COL])a;

}


int (*func4(void))[SET][ROW][COL] {

    printf("\nCalling Function: %s\n", __func__);

    int i, j, k;
    static int a[SET][ROW][COL] = {
                                    {
                                      1, 2, 3, 4,
                                      5, 6, 7, 8,
                                      9, 10, 11, 12
                                    },
                                    {
                                      11, 22, 33, 44,
                                      55, 66, 77, 88,
                                      99, 110, 111, 112
                                    }
                                  };

    for (i = 0;i < SET; i++) {
        for (j = 0; j < ROW; j++) {
            for (k = 0; k < COL; k++) {
                printf("%d, ", a[i][j][k]);
            }
            printf("\n");
        }
        printf("\n");
    }

    return (int (*)[SET][ROW][COL])a;

}


int main (void) {

    int i, j, k;
    int *p;
    int (*q)[COL];
    int (*a)[COL];
    int (*r)[ROW][COL];
    int (*s)[SET][ROW][COL];

    p = func1();
    
    printf("\nCalling Function: %s\n", __func__);
    
    for (i = 0;i < SET; i++) {
        for (j = 0; j < ROW; j++) {
            for (k = 0; k < COL; k++) {
                printf("%d, ", *(p + i*ROW*COL + j*COL + k));
            }
            printf("\n");
        }
        printf("\n");
    }

    q = func2();
    
    printf("\nCalling Function: %s\n", __func__);
    
    for (i = 0;i < SET*ROW; i++) {
       a = q + i;
       for (k = 0; k < COL; k++) {
           printf("%d, ", *(*a + k));
       }
       printf("\n");
    }

    r = func3();

    printf("\nCalling Function: %s\n", __func__);
    
    for (i = 0;i < SET*ROW; i++) {
       a = *r + i;
       for (k = 0; k < COL; k++) {
           printf("%d, ", *(*a + k));
       }
       printf("\n");
    }    

    s = func4();

    printf("\nCalling Function: %s\n", __func__);
    
    for (i = 0;i < SET; i++) {
        for (j = 0; j < ROW; j++) {
            for (k = 0; k < COL; k++) {
                printf("%d, ", (*s)[i][j][k]);
            }
            printf("\n");
        }
        printf("\n");
    }

    return 0;

}
