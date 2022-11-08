#include <stdio.h>
#define MAXN 20
#define INF 10000000

int max (int a, int b) {
    if (a > b) {
        return a;
    } else {
        return b;
    }

}

int max_value (int index, int knapsack[MAXN][2], int capacity, int value, int n) {
    if (capacity < 0) return -INF;
    if (index == n) return value;
    return max(max_value(index + 1, knapsack, capacity - knapsack[index][0], value + knapsack[index][1], n), 
    max_value(index + 1, knapsack, capacity, value, n));
}

int main () {
    int n;
    int capacity;
    scanf("%d%d", &n, &capacity);
    int knapsack[MAXN][2] = {};
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &knapsack[i][0], &knapsack[i][1]);
    }
    printf("%d", max_value(0, knapsack, capacity, 0, n));
}