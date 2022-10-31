#include <stdio.h>
#include <string.h>
int get_digit (char cur) {
    char digits[] = {')', '!', '@', '#', '$', '%', '^', '&', '*', '('};
    int ret = 0;

    while (cur != digits[ret] && ret <= 9)
    {
        ret++;
    }
    return ret;
}

int main () {
    int sum = 0;
    int product = 1;
    int now = 0;
    char cur;
    
    while (scanf("%c", &cur) != EOF) {
        //printf("%c\n", exp[i]);
        if (cur == '*') {
            product *= now;
            now = 0;
        } else if (cur == '+') {
            product *= now;
            sum += product;
            product = 1;
            now = 0;
        } else {
            
            int digit = get_digit(cur);
            if (digit != 10) {
                now *= 10;
                now += digit;
            }
        }
        //printf("%d\n", sum + product * now);
    }
    product *= now;
    printf("%d\n", sum + product);
}