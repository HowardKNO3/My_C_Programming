#include <stdio.h>
#include <stdbool.h>

int main () {
    int n, k;
    scanf("%d%d", &n, &k);
    int ans = 1;
    while (true) {
        int temp = ans;
        bool valid = true;
        for (int i = 0; i < n; i++) {
            //printf("%d ", temp);
            if (temp % n == k) {
                temp -= k;
                if (temp / n == 0) {
                    valid = false;
                }
                temp -= temp / n;
                
            } else {
                valid = false;
            }
        }
        //printf("\n");
        if (!valid) {
            ans++;
        } else {
            break;
        }
    }
    printf("%d", ans);
}