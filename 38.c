#include <stdio.h>
#include <stdbool.h>
#define ll long long
int main () {
    int t;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        ll target;
        scanf("%lld", &target);
        ll a_t, b_t, c_t;
        scanf("%lld%lld%lld", &a_t, &b_t, &c_t);
        ll a_v, b_v, c_v;
        scanf("%lld%lld%lld", &a_v, &b_v, &c_v);
        bool found = false;
        for (ll a = 0; a <= a_t && !found; a++) {
            for (ll b = 0; b <= b_t && !found; b++) {
                for (ll c = 0; c <= c_t && !found; c++) {
                    if (a * a_v + b * b_v + c * c_v == target) {
                        found = true;
                        break;
                    }
                    
                }
            }
        }
        if (found) {
            printf("yes\n");
        } else {
            printf("no\n");
        }
        
    }
}