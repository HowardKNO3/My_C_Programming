#include <stdio.h>
#include <stdbool.h>

int main() {
    int n;
    scanf("%d", &n);
    bool divided_by_3 = (n % 3 == 0);
    bool divided_by_5 = (n % 5 == 0);
    bool divided_by_7 = (n % 7 == 0);
    printf("%d", !(divided_by_3 && divided_by_5 && !divided_by_7));
}