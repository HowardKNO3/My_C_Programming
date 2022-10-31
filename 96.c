#include <stdio.h>
#define pi 3.1415926

int main () {
    double a, b, c;
    scanf("%lf%lf%lf", &a, &b, &c);
    double ans = 0;
    ans += c * c * pi * 3 / 4;
    //printf("%f\n", c * c * pi * 3 / 4);
    ans += (c - a > 0) ? ((c - a) * (c - a) * pi / 4) : 0;
    //printf("%f\n", (c - a) * (c - a) * pi / 4);
    ans += (c - b > 0) ? ((c - b) * (c - b) * pi / 4) : 0;
    //printf("%f\n", (c - b) * (c - b) * pi / 4);
    printf("%lf", ans);
}