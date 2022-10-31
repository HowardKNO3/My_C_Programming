#include <stdio.h>
#include <stdbool.h>


int main () {
    int n, m;
    scanf("%d%d", &n, &m);
    int arr[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
    int ans = 0;
    for (int i = 1; i < n - 1; i++) {
        for (int j = 0; j + 4 <= m; j++) {
            for (int k = j; k < j + 4; k++) {
                for (int l = j; l < j + 4; l++) {
                    bool valid = (arr[i][j] + arr[i][j + 2] == 7) && (arr[i][j + 1] + arr[i][j + 3] == 7) && arr[i - 1][k] + arr[i + 1][l] == 7;
                    
                    int cnt[7] = {0};
                    cnt[arr[i][j]]++;
                    cnt[arr[i][j + 1]]++;
                    cnt[arr[i][j + 2]]++;
                    cnt[arr[i][j + 3]]++;
                    cnt[arr[i - 1][k]]++;
                    cnt[arr[i + 1][l]]++;
                    for (int index = 1; index <= 6; index++) {
                        valid = valid && (cnt[index] == 1);
                    }
                    if (valid) {
                        ans++;
                    }
                        
                        
                }
            }
        }
    }
    printf("%d", ans);
}

    