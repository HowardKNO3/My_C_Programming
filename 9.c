#include <stdio.h>
#include <stdbool.h>

int main() {
    int x;
    scanf("%d", &x);
    if(x <= 0) {
        printf("%d", -100);
    }
    else {
        int score = 0;
        if (x % 3 == 0) {
            score += 3;
        }
        if (x % 5 == 0) {
            score += 5;
        }
        if (x >= 100 && x <= 200) {
            score += 50;
        }
        else {
            score -= 50;
        }
        printf("%d", score);
    }
}