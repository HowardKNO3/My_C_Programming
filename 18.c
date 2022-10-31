#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int main() {
    int r, c;
    scanf("%d%d", &r, &c);
    int arr[r + 2][c + 2];
    memset(arr, 0, sizeof(arr));
    for (int i = 1; i <= r; i++){
        for (int j = 1; j <= c; j++)
        {
            scanf("%d", &arr[i][j]);
        }
        
    }
    #ifdef DEBUG
    for (int i = 0; i <= r + 1; i++){
        for (int j = 0; j <= c + 1; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    #endif
    for (int i = 1; i <= r; i++){
        for (int j = 1; j <= c; j++)
        {
            if (arr[i][j] > arr[i - 1][j] &&
            arr[i][j] > arr[i + 1][j] &&
            arr[i][j] > arr[i][j + 1] &&
            arr[i][j] > arr[i][j - 1]) {
                printf("%d\n", arr[i][j]);
            }
        }
        
    }
}