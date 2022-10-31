#include <stdio.h>
#include <stdbool.h>

int main() {
    int r, c;
    scanf("%d%d", &r, &c);
    int sum[c];
    for (int i = 0; i < c; i++){
        sum[i] = 0;
    }
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            int temp;
            scanf("%d", &temp);
            sum[j] += temp;
        }
    }
    #ifdef DEBUG
    for (int i = 0; i < c; i++){
        printf("%d", sum[i]);
    }
    #endif
    for (int i = 0; i < c; i++){
        printf("%d\n", (sum[i] / r));
    }
}