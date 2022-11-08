#include <stdio.h>

int max (int a, int b) {
    return (a > b) ? a : b;
}

int main () {
    int num;
    while (scanf("%d", &num) != EOF)
    {
        int max_cnt = 0;
        int cnt = 0;
        while (num > 0)
        {
            if (num % 2 == 1) cnt++;
            else {
                max_cnt = max(cnt, max_cnt);
                cnt = 0;
            } 
            num /= 2;
            //printf("%d\n", cnt);
        }
        max_cnt = max(cnt, max_cnt);
        printf("%d\n", max_cnt);
    }
    
}