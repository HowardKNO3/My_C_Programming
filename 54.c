#include <stdio.h>
#include <stdbool.h>

int main() {
    int n, m;
    int count = 0;
    scanf("%d%d", &n, &m);
    while (m > 0) {
        if (m % 100 == n) {
            count++;
        }
        m /= 10;
    }
    printf("%d", count);
}