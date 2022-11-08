#include <stdio.h>

int ways (int n, int m) {
    if (n < 1 || m < 1) return 0;
    if (n == 1 && m == 1) return 1;
    return ways(n - 1, m) + ways(n, m - 1);
} 

int main () {
    int n, m;
    scanf("%d%d", &n, &m);
    printf("%d", ways(n, m));
}