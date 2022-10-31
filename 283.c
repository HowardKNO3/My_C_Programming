#include <stdio.h>
#include <stdbool.h>

int main() {
    int s, f, t;
    scanf("%d%d%d", &s, &f, &t);
    int chicken = -f / 2 + 4 * s - 2 * t;
    int rabbit = f / 2 - 4 * s + 3 * t;
    int crab = s - t;
    printf("%d\n%d\n%d", chicken, rabbit, crab);
}