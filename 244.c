#include <stdio.h>
#include <stdbool.h>


int main() {
    int first_prize[3] = {0};
    int special_prize[3] = {0};
    for (int i = 0; i < 3; i++) {
        scanf("%d", &special_prize[i]);
    }
    for (int i = 0; i < 3; i++) {
        scanf("%d", &first_prize[i]);
    }
    
    int ans = 0;
    int cur;
    int p[9] = {0, 0, 0, 200, 1000, 4000, 10000, 40000, 200000}; 
    while (scanf("%d", &cur) != EOF) {
        for (int i = 0; i < 3; i++) {
            int digit = 0;
            int div = 10;
            while (cur % div == first_prize[i] % div && digit < 8)
            {
                digit++;
                div *= 10;
            }
            //printf("%d %d\n", cur % div, first_prize[i] % div);
            ans += p[digit];
            
        }
        for (int i = 0; i < 3; i++) {
            if (cur == special_prize[i]) {
                ans += 2000000;
            }
        }
        //printf("%d\n", ans);
    }
    printf("%d", ans);
}