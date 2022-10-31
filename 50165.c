#include <stdio.h>
#include <math.h>

int main () {
    int n;
    scanf("%d", &n);
    double equation[n][3];
    for (int i = 0; i < n; i++) {
        scanf("%lf%lf%lf", &equation[i][0], &equation[i][1], &equation[i][2]);
    }
    double coord[n][2];
    for (int i = 0; i < n; i++) {
        double delta = equation[i][0] * equation[(i + 1) % n][1] - equation[(i + 1) % n][0] * equation[i][1];
        double delta_x = equation[i][2] * equation[(i + 1) % n][1] - equation[(i + 1) % n][2] * equation[i][1];
        double delta_y = equation[i][0] * equation[(i + 1) % n][2] - equation[(i + 1) % n][0] * equation[i][2];
        coord[i][0] = delta_x / delta;
        coord[i][1] = delta_y / delta;
    }
    double ans = 0;
    ans = 0;
    for (int i = 0; i < n; i++) {
        ans += sqrt((coord[i][0] - coord[(i + 1) % n][0]) * (coord[i][0] - coord[(i + 1) % n][0]) + (coord[i][1] - coord[(i + 1) % n][1]) * (coord[i][1] - coord[(i + 1) % n][1]));
    }
    printf("%.3lf", ans);
}
