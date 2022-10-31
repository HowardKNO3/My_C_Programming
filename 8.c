#include <stdio.h>
#include <stdbool.h>

int main() {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    bool sit_1 = ((a + b) > c);
    bool sit_2 = ((a + c) > b);
    bool sit_3 = ((c + b) > a);
    printf("%d", (sit_1 && sit_2 && sit_3));
}