#include <stdio.h>
#include <stdbool.h>

int gcd(int a, int b){
    #ifdef DEBUG
        printf("%d %d\n", a, b);
    #endif
    if (b == 0){
        return a;
    }
    return gcd(b, a % b);
}

int main() {
    int a, b, c, d, e, f, g;
    scanf("%d%d%d%d%d%d%d", &a, &b, &c, &d, &e, &f, &g);
    int a_top = a * c;
    if (a > 0) {
        a_top += b;
    } else {
        a_top -= b;
    }
    int a_bottom = c;
    int b_top = e * g;
    if (e > 0) {
        b_top += f;
    } else {
        b_top -= f;
    }
    int b_bottom = g;
    int res_bottom, res_top, res_int;
    if (d == 0) {
        res_bottom = a_bottom * b_bottom;
        res_top = a_top * b_bottom + b_top * a_bottom;    
    } else if (d == 1) {
        res_bottom = a_bottom * b_bottom;
        res_top = a_top * b_bottom - b_top * a_bottom;
    } else if (d == 2) {
        res_bottom = a_bottom * b_bottom;
        res_top = a_top * b_top;
    } else {
        res_bottom = a_bottom * b_top;
        res_top = a_top * b_bottom;
        if (res_bottom < 0) {
            res_bottom *= -1;
            res_top *= -1;
        }
    }
    
    
    int div = gcd(((res_bottom > 0) ? res_bottom : -res_bottom), ((res_top > 0) ? res_top : -res_top));
    res_top /= div;
    res_bottom /= div;
    #ifdef DEBUG
        printf("%d %d %d\n", res_top, res_bottom, div);
    #endif
    res_int = res_top / res_bottom;
    res_top %= res_bottom;
    if (res_top < 0) {
        res_top *= -1;
    }
    printf("%d\n%d\n%d", res_int, res_top, res_bottom);
}