#include <stdio.h>

void work(int size, int type, int center_x, int center_y) {
    if (size == 1) {
        printf("%d %d %d\n", (type + 1), center_x, center_y);
        return;
    }
    int adjust[4][3][2] = {
    {{-1, 1}, {-1, -1}, {1, -1}},
    {{-1, -1}, {1, -1}, {1, 1}},
    {{1, -1}, {1, 1}, {-1, 1}},
    {{1, 1}, {-1, 1}, {-1, -1}}
    };
    work(size / 2, type, center_x, center_y);
    work(size / 2, (type + 3) % 4, center_x + (adjust[type][0][0]) * size / 2, center_y + (adjust[type][0][1]) * size / 2);
    work(size / 2, type, center_x + (adjust[type][1][0]) * size / 2, center_y + (adjust[type][1][1]) * size / 2);
    work(size / 2, (type + 1) % 4, center_x + (adjust[type][2][0]) * size / 2, center_y + (adjust[type][2][1]) * size / 2);
}

int main () {
    int n, m;
    scanf("%d%d", &n, &m);
    int now_center = 0;
    for (int i = n; i > m; i /= 2) {
        now_center += i / 2;
        work(i / 2, 0, now_center, now_center);
    }
    
}