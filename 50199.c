#include <stdio.h>
#include <stdbool.h>
#define MAXR 505
#define MAXC 505

int remove_type (int chart[MAXC][MAXR], int now_r, int now_c) {
    int types[6][2][2] = {{{0, 1}, {0, 2}},
                        {{0, 1}, {1, 1}},
                        {{1, 0}, {1, 1}},
                        {{1, 0}, {0, 1}},
                        {{1, 0}, {2, 0}},
                        {{1, 0}, {1, -1}}};
    for (int i = 0; i < 6; i++) {
        bool same_1 = chart[now_r + types[i][0][0]][now_c + types[i][0][1]] == chart[now_r][now_c];
        bool same_2 = chart[now_r + types[i][1][0]][now_c + types[i][1][1]] == chart[now_r][now_c];
        if (same_1 && same_2) {
            return i;
        }
    }
    return -1;
}

void remove_chart (int chart[MAXC][MAXR], int type, int now_r, int now_c) {
    int types[6][2][2] = {{{0, 1}, {0, 2}},
                        {{0, 1}, {1, 1}},
                        {{1, 0}, {1, 1}},
                        {{1, 0}, {0, 1}},
                        {{1, 0}, {2, 0}},
                        {{1, 0}, {1, -1}}};
    chart[now_r][now_c] = 0;
    chart[now_r + types[type][0][0]][now_c + types[type][0][1]] = 0;
    chart[now_r + types[type][1][0]][now_c + types[type][1][1]] = 0;
    return;
} 

int main () {
    int r, c;
    scanf("%d%d", &r, &c);
    int chart[MAXR][MAXC] = {0};
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            scanf("%d", &chart[i][j]);
        }
    }
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            /*
            for (int i = 0; i < r; i++) {
                for (int j = 0; j < c; j++) {
                    printf("%d ", chart[i][j]);
                }
                printf("\n");
            }
            */
            if (chart[i][j] == 0) {
                continue;
            }
            int type = remove_type(chart, i, j);
            if (type == -1) {
                continue;
            } else {
                remove_chart(chart, type, i, j);
            }
        }
    }
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            printf("%d ", chart[i][j]);
        }
        printf("\n");
    }
}