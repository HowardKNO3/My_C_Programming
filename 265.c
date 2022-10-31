#include <stdio.h>
#define INF 1000000000
int main () {
    int min_x = INF;
    int max_x = -INF;
    int min_y = INF;
    int max_y = -INF;
    int cur_x, cur_y;
    while (scanf("%d%d", &cur_x, &cur_y) != EOF)
    {
        min_x = (cur_x < min_x) ? cur_x : min_x;
        min_y = (cur_y < min_y) ? cur_y : min_y;
        max_x = (cur_x > max_x) ? cur_x : max_x;
        max_y = (cur_y > max_y) ? cur_y : max_y;
    }
    printf("%d", (max_x - min_x) * (max_y - min_y));
}