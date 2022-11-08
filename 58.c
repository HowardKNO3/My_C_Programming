#include <stdio.h>
#define MAXN 405

int lake_size(int map[MAXN][MAXN], int i, int j) {
    map[i][j] = 0;
    int sum = 1;
    if (map[i + 1][j] == 1) sum += lake_size(map, i + 1, j);
    if (map[i - 1][j] == 1) sum += lake_size(map, i - 1, j);
    if (map[i][j + 1] == 1) sum += lake_size(map, i, j + 1);
    if (map[i][j - 1] == 1) sum += lake_size(map, i, j - 1);
    return sum;
}

int main () {
    int n, m;
    int map[MAXN][MAXN] = {};
    int lakes[MAXN * MAXN / 2] = {};
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%d", &map[i][j]);
        }
    }
    int lake_cnt = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (map[i][j] == 1) {
                lakes[lake_cnt] = lake_size(map, i, j);
                lake_cnt++;
            }
            
        }
    }
    
    for (int i = lake_cnt - 1; i >= 0; i--) {
        for (int j = 0; j < i; j++) {
            if (lakes[j] < lakes[j + 1]) {
                int temp = lakes[j];
                lakes[j] = lakes[j + 1];
                lakes[j + 1] = temp;
            }
        }
    }
    for (int i = 0; i < lake_cnt; i++) {
        printf("%d\n", lakes[i]);
    }
}