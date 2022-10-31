# define ROW 3
# define COL 5
# include<stdio.h>
# include<stdlib.h>
typedef int A[ROW][COL];
typedef int B[COL][ROW];
typedef int C[ROW][ROW];
void multiplyMatrix(void ** arrayA, void ** arrayB, void ** arrayC) {
    int size = 0;
    while (arrayA[size] != NULL)
    {
        size++;
    }
    //printf("%d", size);
    for (int t = 0; t < size; t++) {
        for (int i = 0; i < ROW; i++) {
            for (int j = 0; j < ROW; j++) {
                int *ans = arrayC[t] + ((i * ROW) + j) * sizeof(int);
                *ans = 0;
                for (int k = 0; k < COL; k++) {
                    int *v1 = arrayA[t] + (i * COL + k) * sizeof(int);
                    int *v2 = arrayB[t] + (k * ROW + j) * sizeof(int);
                    //printf("%d %d %d %d %d %d\n", i, j, k, *v1, *v2, (*v1 * *v2));
                    *ans += *v1 * *v2;
                }
            }
        }
    }
    return;
    
}