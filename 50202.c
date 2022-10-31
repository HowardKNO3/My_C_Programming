#include <stdio.h>
#define MAXR 205
#define MAXC 205
#define INF 1000000000
int max (int a, int b) {
    return a > b ? a : b;
}
int calculate_diamond(int chart[MAXR][MAXC], int now_r, int now_c, int r, int c, int size) {
    int ret = 0;
    //printf("%d %d\n", now_r, now_c);
    if (now_c + size - 1 >= c || now_c - size + 1 < 0 || now_r + 2 * (size - 1) >= r) return -INF;
    for (int i = 0; i < size; i++) {
        if (i == 0) ret += chart[now_r + i][now_c + i];
        else {
            ret += chart[now_r + i][now_c + i];
            ret += chart[now_r + i][now_c - i];
        }
    }
    for (int i = 0; i < size - 1; i++) {
        if (i == 0) ret += chart[now_r + 2 * (size - 1)][now_c + i];
        else {
            ret += chart[now_r + 2 * (size - 1) - i][now_c + i];
            ret += chart[now_r + 2 * (size - 1) - i][now_c - i];
        }
    }
    //printf("%d %d %d\n", now_r, now_c, ret);
    return ret;
}
int main () {
    int r, c, k;
    scanf("%d%d%d", &r, &c, &k);
    int chart[MAXR][MAXC];
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            scanf("%d", &chart[i][j]);
        }
    }
    int ans = -INF;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            //printf("%d %d\n", i, j);
            ans = max(calculate_diamond(chart, i, j, r, c, k), ans);
        }
        
    }
    printf("%d", ans);
}