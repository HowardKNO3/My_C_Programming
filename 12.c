#include <stdio.h>
#include <stdbool.h>

int main() {
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        printf("%d\n", i);
    }
    for(int i = n - 1; i >= 2; i--){
        printf("%d\n", i);
    }
    if(n != 1) {
        printf("%d", 1);
    }
    
}