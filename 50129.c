#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "loops.h"
#define MAXN 1000000
#define INF 1000000000

int min (int a, int b) {
    return (a < b) ? a : b;
}

int max (int a, int b) {
    return (a > b) ? a : b;
}

void loops(int N, int *A, int *B[], int ans[4]) {
    ans[0] = -INF;
    ans[1] = INF;
    ans[2] = -INF;
    ans[3] = INF;
    bool visited[N];
    for (int i = 0; i < N; i++) {
        visited[i] = false;
    }
    for (int i = 0; i < N; i++) {
        
        if (!visited[i]) {
            int index = i;
            int count = 0;
            int min_num = INF;
            int max_num = -INF;
            while (!visited[index]) {
                min_num = min(A[index], min_num);
                max_num = max(A[index], max_num);
                visited[index] = true;
                count++;
                index = (B[index]) - A;
            }
            //printf("%d\n", count);
            if (count > ans[0]) {
                ans[0] = count;
                ans[2] = max_num;
            } else if (count == ans[0]) {
                ans[2] = max(ans[2], max_num);
            }
            if (count < ans[1]) {
                ans[1] = count;
                ans[3] = min_num;
            } else if (count == ans[1]) {
                ans[3] = min(ans[3], min_num);
            }
        }
        
        
    }
}

int main(){
    int N;
    int *A = (int *)malloc(sizeof(int) * MAXN);
    int **B = (int **)malloc(sizeof(int *) * MAXN);
    scanf("%d", &N);
    for(int i = 0; i < N; i++)
        scanf("%d", A + i);
    for(int i = 0, ptr; i < N; i++){
        scanf("%d", &ptr);
        B[i] = A + ptr;
    }
    int ans[4];
    loops(N, A, B, ans);
    for(int i = 0; i < 4; i++)
        printf("%d\n", ans[i]);
    return 0;
}