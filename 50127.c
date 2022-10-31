#include <stdio.h>
#define MAXN 200

void constructPointerArray(const int A[MAXN][MAXN], const int *B[MAXN][MAXN], int N) {
    const int *location[N * N];
    
    for (int i = 0; i < N * N; i++) {
        location[i] = NULL;
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            location[A[i][j]] = &A[i][j];
        }
    } 
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int cur = A[i][j];
            if (cur + 1 < N * N) {
                B[i][j] = location[cur + 1];
            } else {
                B[i][j] = location[0];
            }
            
        }
    }
    
}

int main()
{
    int A[MAXN][MAXN];
    const int *B[MAXN][MAXN];
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &A[i][j]);
        }
    }
    constructPointerArray(A, B, N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d%c", *B[i][j], j == N - 1 ? '\n' : ' ');
        }
    }
    return 0;
}