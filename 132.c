#include <stdio.h>
#include <stdbool.h>
#define MAXN 20
#define MAXC 10

bool solve (int n, int c, int colors[MAXN], int edges[MAXN][MAXN], int index) {
    if (index == n) return true;
    else {
        bool ret = false;
        bool used[MAXC] = {};
        for (int i = 0; i < n; i++) {
            if (edges[index][i] == 1) {
                used[colors[i]] = true;
            }
        }
        for (int i = 1; i <= c && !ret; i++) {
            if (!used[i]) {
                colors[index] = i;
                ret = ret || solve(n, c, colors, edges, index + 1);
            }
            if (!ret) {
                colors[index] = 0;
            }
        }
        return ret;
    }
}

int main () {
    int n, c, edge_cnt;
    scanf("%d%d%d", &n, &c, &edge_cnt);
    int colors[MAXN] = {};
    int edges[MAXN][MAXN] = {};
    for (int i = 0; i < edge_cnt; i++) {
        int n1, n2;
        scanf("%d%d", &n1, &n2);
        edges[n1][n2] = 1;
        edges[n2][n1] = 1;
    }
    if (solve(n, c, colors, edges, 0)) {
        for (int i = 0; i < n; i++) {
            printf("%d\n", colors[i]);
        }
    } else {
        printf("no solution.\n");
    }
}