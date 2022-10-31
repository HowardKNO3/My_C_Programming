# include<stdio.h>
# include<stdlib.h>
# define ROW 3
# define COL 5
typedef int A[ROW][COL];
typedef int B[COL][ROW];
typedef int C[ROW][ROW];
# define MAX 10

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

int main() {
    int size = 0;
    scanf("%d", &size);

    void ** arrayA = malloc((size + 1) * sizeof(int*));
    void ** arrayB = malloc((size + 1) * sizeof(int*));
    void ** arrayC = malloc((size + 1) * sizeof(int*));

    A matrixA[MAX];
    B matrixB[MAX];
    C matrixC[MAX];
    for (int n = 0; n < size; n++) {
        for (int i = 0; i < ROW; i++)
            for (int j = 0; j < COL; j++)
                scanf("%d", &matrixA[n][i][j]);

        for (int i = 0; i < COL; i++)
            for (int j = 0; j < ROW; j++)
                scanf("%d", &matrixB[n][i][j]);

        arrayA[n] = &matrixA[n];
        arrayB[n] = &matrixB[n];
        arrayC[n] = &matrixC[n];
    }

    arrayA[size] = NULL;
    arrayB[size] = NULL;
    arrayC[size] = NULL;

    multiplyMatrix(arrayA, arrayB, arrayC);

    for (int n = 0; n < size; n ++) {
        for (int i = 0; i < ROW; i ++) {
            for (int k = 0; k < ROW; k++) {
                printf("%d ", matrixC[n][i][k]);
            }
            printf("\n");
        }
        printf("\n");
    }

    return 0;
}