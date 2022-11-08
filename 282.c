#include <stdio.h>

int main () {
    long long num;
    while (scanf("%lld", &num) != EOF)
    {
        int cnt = 0;
        while (num > 0)
        {
            if (num % 2 == 1) cnt++;
            num /= 2;
            
        }
        printf("%d\n", cnt);
    }
    
}