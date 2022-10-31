#include <stdio.h>
#include <stdbool.h>

int main() {
    int y, d;
    scanf("%d%d", &y, &d);
    int month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (y % 4 == 0 && y % 400 != 0) {
        month[1]++;
    }
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++){
        int target_month, target_day;
        scanf("%d%d", &target_month, &target_day);
        if (target_month < 0 || target_month > 12)
        {
            printf("-1\n");
            continue;
        } 
        
        if(target_day <= 0 || target_day > month[target_month - 1]) {
            printf("-2\n");
            continue;
        }
        
        
        int now_d = 0;
        for (int j = 0; j < target_month - 1; j++) {
            now_d += month[j];
        }
        now_d += target_day;
        now_d += d;
        printf("%d\n", (now_d - 1) % 7);
        
        
    }
}