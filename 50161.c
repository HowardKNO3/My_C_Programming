#include <stdio.h>

int main () {
    int n;
    scanf("%d", &n);
    int appear[101];
    for (int i = 1; i <= 100; i++)
    {
        appear[i] = -1;
    }
    
    for (int i = 0; i < n; i++) {
        int cur;
        scanf("%d", &cur);
        printf("%d", i);
        if (appear[cur] != -1) {
            printf(" %d %d", appear[cur], cur);
            appear[cur] = -1;
        } else {
            appear[cur] = i;
        }
        printf("\n");
    }
    
}