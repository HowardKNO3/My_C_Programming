#include <stdio.h>
#define MAXN 15

int methods (int index, int target, int value[MAXN], int n) {
    if (target == 0) {
        return 1;
    } 
    if (index == n) {
        return 0;
    }
    return methods(index + 1, target - value[index], value, n) + methods(index + 1, target, value, n);
}

int main () {
    int value[MAXN] = {};
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &value[i]);
    }
    int target = 0;
    while (scanf("%d", &target) != EOF)
    {
        printf("%d\n", methods(0, target, value, n));
    }
    
}