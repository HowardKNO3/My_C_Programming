#include <stdio.h>
#include <stdbool.h>

int main() {
    int a1, a2, b1, b2, c1, c2, d1, d2;
    scanf("%d%d%d%d%d%d%d%d", &a1, &a2, &b1, &b2, &c1, &c2, &d1, &d2);
    bool a_cross_b = a1 * b2 - a2 * b1 > 0;
    bool b_cross_c = b1 * c2 - b2 * c1 > 0;
    bool c_cross_d = c1 * d2 - c2 * d1 > 0;
    bool d_cross_a = d1 * a2 - d2 * a1 > 0;
    if (a_cross_b && b_cross_c && c_cross_d && d_cross_a) {
        printf("1");
    } else {
        printf("0");
    }
}