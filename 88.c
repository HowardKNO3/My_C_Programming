#include <stdio.h>
#include <stdbool.h>

int main() {
    int m, n;
    scanf("%d%d", &m, &n);
    int digit_m[4], digit_n[4];
    for (int i = 0; i < 4; i++) {
        digit_m[i] = m % 10;
        m /= 10;
        digit_n[i] = n % 10;
        n /= 10;
    }
    int a = 0, b = 0;
    for (int i = 0; i < 4; i++) {
        if (digit_m[i] == digit_n[i]) {
            a++;
        }
    }
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (digit_m[i] == digit_n[j]) {
                b++;
            }
        }
    }
    b -= a;
    printf("%dA%dB", a, b);
}