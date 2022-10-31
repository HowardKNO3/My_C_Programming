#include <stdio.h>
#include <stdbool.h>

int main() {
    int n;
    scanf("%d", &n);
    int rem_0 = 0, rem_1 = 0, rem_2 = 0;
    for(int i = 0; i < n; i++) {
        int temp;
        scanf("%d", &temp);
        if (temp % 3 == 0) {
            rem_0++;
        } else if (temp % 3 == 1) {
            rem_1++;
        } else {
            rem_2++;
        }
    }
    printf("%d %d %d", rem_0, rem_1, rem_2);
}