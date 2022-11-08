#include <stdio.h>
#define MAXN 20

int work(int index, int now_sum, int now_cnt, int low, int n, int numbers[MAXN], int target) {
    if (now_sum > target) return 0;
    if (index == n) {
        if (now_cnt < low) return 0;
        else return 1;
    }
    return work(index + 1, now_sum + numbers[index], now_cnt + 1, low, n, numbers, target) + 
        work(index + 1, now_sum, now_cnt, low, n, numbers, target);
}

int main () {
    int low;
    int n;
    int target;
    scanf("%d %d %d", &low, &n, &target);
    int numbers[MAXN] = {};
    for (int i = 0; i < n; i++) {
        scanf("%d", &numbers[i]);
    }
    printf("%d", work(0, 0, 0, low, n, numbers, target));
}