#include <stdio.h>
int main() {
    int n;
    scanf("%d", &n);
    int first_digit = n / 100;
    n %= 100;
    int second_digit = n / 10;
    n %= 10;
    int third_digit = n;
    printf("%d\n%d\n%d", first_digit, second_digit, third_digit);
}