#include <stdio.h>
#include <stdbool.h>
#define MAXH 505
#define MAXW 505

void attack (int chart[MAXH][MAXW], int dir_x, int dir_y, int x, int y, int h, int w) {
    while (true)
    {
        x += dir_x;
        y += dir_y;
        bool valid = (x >= 0 && x < w && y >= 0 && y < h) && chart[x][y] == 0;
        if (valid) {
            chart[x][y] = 1;
        } else {
            break;
        }
    }
    return;
}

void rook_attack (int chart[MAXH][MAXW], int x, int y, int h, int w) {
    //printf("%d %d\n", x, y);
    int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    for (int i = 0; i < 4; i++)
    {
        attack(chart, dir[i][0], dir[i][1], x, y, h, w);
    }
    return;
}

void bishop_attack (int chart[MAXH][MAXW], int x, int y, int h, int w) {
    //printf("%d %d\n", x, y);
    int dir[4][2] = {{1, 1}, {-1, 1}, {1, -1}, {-1, -1}};
    for (int i = 0; i < 4; i++)
    {
        attack(chart, dir[i][0], dir[i][1], x, y, h, w);
    }
    return;
}

void queen_attack (int chart[MAXH][MAXW], int x, int y, int h, int w) {
    //printf("%d %d\n", x, y);
    rook_attack(chart, x, y, h, w);
    bishop_attack(chart, x, y, h, w);
    return;
}

int main () {
    int h, w;
    scanf("%d%d", &h, &w);
    int chart[MAXH][MAXW] = {0};
    int x, y, type;
    while (scanf("%d%d%d", &type, &x, &y) != EOF) {
        //printf("x : %d y : %d\n", x, y);
        /*
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                printf("%d ", chart[i][j]);
            }
            printf("\n");
        }
        */
        if (type == 1) {
            queen_attack(chart, x, y, h, w);
        } else if (type == 2) {
            bishop_attack(chart, x, y, h, w);
        } else if (type == 3){
            rook_attack(chart, x, y, h, w);
        }
        chart[x][y] = 1;
    }
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            printf("%d ", chart[j][i]);
        }
        printf("\n");
    }
}