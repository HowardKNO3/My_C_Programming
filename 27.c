#include <stdio.h>
#include <stdbool.h>

int main() {
    int area = 0, volume = 0;
    int a, b, c, d, e;
    scanf("%d%d%d%d%d", &a, &b, &c, &d, &e);
   
    area += 2 * a * b + 2 * b * c + 2 * a * c;
    area += 8 * d * (a - 2 * e);
    area += 8 * d * (b - 2 * e);
    area += 8 * d * (c - 2 * e);

    volume += a * b * c;
    volume -= 2 * d * (a - 2 * e) * (b - 2 * e);
    volume -= 2 * d * (c - 2 * e) * (b - 2 * e);
    volume -= 2 * d * (a - 2 * e) * (c - 2 * e);
    printf("%d\n%d", area, volume);
}