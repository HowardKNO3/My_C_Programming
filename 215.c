#include <stdio.h>
#include <stdbool.h>

int main() {
    int s, f, t;
    scanf("%d%d%d", &s, &f, &t);
    int chicken = -f / 2 + 4 * s - 2 * t;
    int rabbit = f / 2 - 4 * s + 3 * t;
    int crab = s - t;
    bool sum_ok =  (chicken + rabbit + crab == s);
    bool foot_ok =  (chicken * 2 + rabbit * 4 + crab * 8 == f);
    bool tail_ok =  (chicken + rabbit == t);
    bool pos = chicken >= 0 && rabbit >= 0 && crab >= 0;
    if (sum_ok && foot_ok && tail_ok && pos) {
        printf("%d\n%d\n%d", chicken, rabbit, crab);
    }
    else {
        printf("0");
    }
    
}