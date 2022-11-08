#include <stdio.h>
#define MAXN 13
int ways (int now_n, int now_m, int n, int m, int map[MAXN][MAXN]) {
    if (now_n >= n || now_m >= m || map[now_n][now_m] == 0) return 0;
    if (now_n == n - 1 && now_m == m - 1) return 1;
    return ways(now_n + 1, now_m, n, m, map) + ways(now_n, now_m + 1, n, m, map);
} 

int main () {
    int n, m;
    scanf("%d%d", &n, &m);
    int map[MAXN][MAXN] = {};
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &map[n - i - 1][j]);
        }
    }
    printf("%d", ways(0, 0, n, m, map));
}