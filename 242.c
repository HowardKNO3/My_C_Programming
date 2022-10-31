#include <stdio.h>
#include <stdbool.h>
#define ll long long int

bool in_circle (ll x1, ll y1, ll x2, ll y2, ll r) {
    
    return (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1) <= r * r;
} 

int main() {
    int t;
    scanf("%d", &t);
    
    for (int tt = 0; tt < t; tt++){
        ll circle[3][3] = {0};
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                scanf("%lld", &circle[i][j]);
            }
        }
        int one_circle = 0;
        int all_circle = 0;
        for (int i = 0; i < 3; i++) {
            for (ll x = circle[i][0] - circle[i][2]; x <= circle[i][0] + circle[i][2]; x++) {
                for (ll y = circle[i][1] - circle[i][2]; y <= circle[i][1] + circle[i][2]; y++) {
                    if (!in_circle(x, y, circle[i][0], circle[i][1], circle[i][2])) {
                        continue;
                    }
                    int cnt = 0;
                    if(in_circle(x, y, circle[0][0], circle[0][1], circle[0][2])) {
                        cnt++;
                    }
                    
                    if(in_circle(x, y, circle[1][0], circle[1][1], circle[1][2])) {
                        cnt++;
                    }
                    
                    if(in_circle(x, y, circle[2][0], circle[2][1], circle[2][2])) {
                        cnt++;
                    }
                    
                    //printf("%d %d %d\n", x, y, cnt);
                    if (cnt == 1) {
                        one_circle++;
                    }
                    if (cnt == 3) {
                        all_circle++;
                    }
                }
            }
        }
        printf("%d\n", one_circle + all_circle / 3);
    }
    
}