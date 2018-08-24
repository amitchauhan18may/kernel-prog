#include<stdio.h>

int main()
{
    int M = 2;
#if 1
    int arr[M][M];
#else
    /*error: variable-sized object may not be initialized*/
    int arr[M][M] = {0}; // Trying to initialize all values as 0
#endif
    int i, j;
    for (i = 0; i < M; i++)
    {
        for (j = 0; j < M; j++)
            printf ("%d ", arr[i][j]);
        printf("\n");
    }
    return 0;
}
