#include <stdio.h>
#define MAXLENGTH 100005

int max (int a, int b, int c) {
    if (a >= b && a >= c) {
        return a;
    } else if (b >= a && b >= c) {
        return b;
    } else {
        return c;
    }
}

void inverse_s_drop (int heights[MAXLENGTH], int coord) {
    int height = max(heights[coord] - 1, heights[coord + 1], heights[coord + 2]);
    heights[coord] = height + 2;
    heights[coord + 1] = height + 2;
    heights[coord + 2] = height + 1;
}

void s_drop (int heights[MAXLENGTH], int coord) {
    int height = max(heights[coord], heights[coord + 1], heights[coord + 2] - 1);
    heights[coord] = height + 1;
    heights[coord + 1] = height + 2;
    heights[coord + 2] = height + 2;
}

void inverse_t_drop (int heights[MAXLENGTH], int coord) {
    int height = max(heights[coord], heights[coord + 1], heights[coord + 2]);
    heights[coord] = height + 1;
    heights[coord + 1] = height + 2;
    heights[coord + 2] = height + 1;
}

void t_drop (int heights[MAXLENGTH], int coord) {
    int height = max(heights[coord] - 1, heights[coord + 1], heights[coord + 2] - 1);
    heights[coord] = height + 2;
    heights[coord + 1] = height + 2;
    heights[coord + 2] = height + 2;
}

int main () {
    int heights[MAXLENGTH] = {0};
    int n;
    scanf("%d", &n);
    int coord, type;
    while (scanf("%d%d", &coord, &type) != EOF) {
        if (type == 0) {
            inverse_s_drop(heights, coord);
        } else if (type == 1) {
            s_drop(heights, coord);
        } else if (type == 2) {
            inverse_t_drop(heights, coord);
        } else {
            t_drop(heights, coord);
        }
    }
    for (int i = 0; i < n; i++) {
        printf("%d ", heights[i]);
    }
    printf("\n");
}