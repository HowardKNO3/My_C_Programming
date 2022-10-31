#include <stdio.h>
#include <stdbool.h>

int main() {
    int t;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        int a1, a2, b1, b2, c1, c2;
        scanf("%d%d%d%d%d%d", &a1, &a2, &b1, &b2, &c1, &c2);
        int ab = (a1 - b1) * (a1 - b1) + (a2 - b2) * (a2 - b2);
        int ac = (a1 - c1) * (a1 - c1) + (a2 - c2) * (a2 - c2);
        int bc = (b1 - c1) * (b1 - c1) + (b2 - c2) * (b2 - c2);
        bool is_isosceles = (ab == bc) || (ab == ac) || (bc == ac);
        bool is_obtuse = (ab + ac < bc) || (ab + bc < ac) || (ac + bc < ab);
        bool is_right = (ab + ac == bc) || (ab + bc == ac) || (ac + bc == ab);
        if (is_isosceles) {
            printf("isosceles\n");
        } else if (is_obtuse) {
            printf("obtuse\n");
        } else if (is_right) {
            printf("right\n");
        } else {
            printf("acute\n");
        }
    }
}