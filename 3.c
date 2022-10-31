#include <stdio.h>
int main(){
    int a = 0, b = 0;
    scanf("%d%d", &a, &b);
    printf("%d\n%d", b, a);
    #ifdef DEBUG
        printf("%d\n", a + b);
    #endif
    return 0;
}