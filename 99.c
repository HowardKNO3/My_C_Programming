#include <stdio.h>
#include <stdbool.h>

int main () {
    int n, m;
    scanf("%d%d", &n, &m);
    char name[10][64] = {0};
    int pos[n][m * m + 1][2];
    for (int i = 0; i < n; i++) {
        scanf("%s", &name[i][0]);
        for (int j = 1; j <= m; j++) {
            for (int k = 1; k <= m; k++) {
                int cur;
                scanf("%d", &cur);
                pos[i][cur][0] = j;
                pos[i][cur][1] = k;
            }
        }
    }
    int vertical[n][m + 1];
    int horizontal[n][m + 1];
    int diagonal[n][2];
    bool winner[n];
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            vertical[i][j] = 0;
            horizontal[i][j] = 0;
        }
        winner[i] = false;
        diagonal[i][0] = 0;
        diagonal[i][1] = 0;
    }
    
    while (true)
    {
        int cur;
        scanf("%d", &cur);
        for (int i = 0; i < n; i++){
            vertical[i][pos[i][cur][1]]++;
            horizontal[i][pos[i][cur][0]]++;
            if (pos[i][cur][0] == pos[i][cur][1])
            {
                diagonal[i][0]++;
            }
            if (pos[i][cur][0] + pos[i][cur][1] == m + 1) {
                diagonal[i][1]++;
            }
            winner[i] = vertical[i][pos[i][cur][1]] == m || horizontal[i][pos[i][cur][0]] == m || diagonal[i][0] == m || diagonal[i][1] == m;
            if (winner[i])
            {
                cnt++;
            }
            
        }
        if (cnt > 0)
        {
            printf("%d ", cur);
            for (int i = 0; i < n; i++) {
                if (winner[i]) {
                    if (cnt == 1)
                    {
                        printf("%s", name[i]);
                    }
                    else {
                        printf("%s ", name[i]);
                    }
                    cnt--;
                }
            }
            break;
            
        }
        
    }
    
    
}