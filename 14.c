#include <stdio.h>
#include <stdbool.h>

int main() {
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &(arr[i]));
    }
    for (int i = n - 1; i > 0; i--) {
        printf("%d ", arr[i]);
    }
    printf("%d", arr[0]);
}