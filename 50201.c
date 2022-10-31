#include <stdio.h>
#include <stdbool.h>
#define MAXR 605
#define MAXC 605

void fold_down(int paper[MAXR][MAXC], int size, int r, int c) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < c; j++) {
            paper[r - 2 * size + i][j] += paper[r - 1 - i][j];
            paper[r - 1 - i][j] = 0;
        }
    }
    return;
}

void fold_left(int paper[MAXR][MAXC], int size, int r, int c) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < r; j++) {
            paper[j][c - 2 * size + i] += paper[j][c - 1 - i];
            paper[j][c - 1 - i] = 0;
        }
    }
    return;
}

void fold_diagonal(int paper[MAXR][MAXC], int size, int r, int c) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (i + j < size - 1) {
                /*
                printf("%d %d\n", i, j);
                printf("%d %d %d %d\n", r - size + i, c - size + j, r - j - 1, c - i - 1);
                */
                paper[r - size + i][c - size + j] += paper[r - j - 1][c - i - 1];
                paper[r - j - 1][c - i - 1] = 0;
            }
            
        }
    }
    return;
}

int main () {
    int paper[MAXR][MAXC] = {0};
    int r, c;
    scanf("%d%d", &r, &c);
    for (int i = r - 1; i >= 0 ; i--) {
        for (int j = 0; j < c; j++) {
            scanf("%d", &paper[i][j]);
        }
    }
    int type = 0, size = 0;
    while (scanf("%d%d", &type, &size) != EOF)
    {
        if (type == 1) {
            fold_down(paper, size, r, c);
            r -= size;
        } else if (type == 2) {
            fold_left(paper, size, r, c);
            c -= size;
        } else {
            fold_diagonal(paper, size, r, c);
        }
    }
    for (int i = r - 1; i >= 0; i--) {
        for (int j = 0; j < c; j++) {
            printf("%d ", paper[i][j]);
        }
        printf("\n");
    }
}