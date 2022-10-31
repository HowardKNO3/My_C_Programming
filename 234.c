#include <stdio.h>
#include <stdbool.h>
#define ll long long

int check (ll a, ll b, ll c, ll i, int now) {
    if(i * i * i + a * i * i + b * i + c == 0) {
        printf("%lld", -i);
        now++;
        if(now != 3) {
            printf(" ");
        }
        if(3 * i * i + 2 * a * i + b == 0) {
            printf("%lld", -i);
            now++;
            if(now != 3) {
                printf(" ");
            }
            if(6 * i + 2 * a == 0) {
                printf("%lld", -i);
                now++;
                if(now != 3) {
                    printf(" ");
                }
            }
        }
    }
    return now;
}

int main() {
    ll a, b, c;
    scanf("%lld%lld%lld", &a, &b, &c);
    int now = 0;
    for (ll i = 100000; i >= -100000; i--) {
        now = check(a, b, c, i, now);
    }
} 