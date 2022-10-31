#include <stdio.h>

int main () {
    int n;
    scanf("%d", &n);
    double arr[n][n + 1];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%lf", &arr[i][j]);
        }
    }
    for (int i = 0; i < n; i++) {
        scanf("%lf", &arr[i][n]);
    }
    double sol[n];
    for (int i = n - 1; i >= 0; i--)
    {
        sol[i] = arr[i][n] / arr[i][i];
        for (int j = 0; j < n; j++)
        {
            arr[j][n] -= sol[i] * arr[j][i];
            arr[j][i] = 0;
        }
        
    }
    for (int i = 0; i < n; i++)
    {
        printf("%lf\n", sol[i]);
    }
    
    
}