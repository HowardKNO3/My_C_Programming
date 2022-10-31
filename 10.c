#include <stdio.h>
#include <stdbool.h>

int main() {
    int x, p;
    scanf("%d%d", &x, &p);
    int ret = 1;
    for(int i = 0 ; i < p ; i++) {
        ret *= x;
    }
    printf("%d", ret);
}