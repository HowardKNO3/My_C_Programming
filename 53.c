#include <stdio.h>
#include <stdbool.h>
#define MAXN 10

void work(int index, int n, int arr[MAXN], int new_arr[MAXN], bool used[MAXN]) {
    if (index == n) {
        for (int i = 0 ; i < n; i++) {
            printf("%d ", new_arr[i]);
        }
        printf("\n");
    } else {
        for (int i = 0; i < n; i++) {
            if (!used[i]) {
                new_arr[index] = arr[i];
                used[i] = true;
                work(index + 1, n, arr, new_arr, used);
                used[i] = false;
                new_arr[index] = 0;
            }
        }
    }
}

int main () {
    int n;
    int arr[MAXN] = {};
    int new_arr[MAXN] = {};
    bool used[MAXN] = {};
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    for (int i = n; i >= 0; i--) {
        for (int j = 0; j < i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    /*
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    */
    work(0, n, arr, new_arr, used);
}