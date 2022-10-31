#include <stdio.h>
#define MAXDEG 15

double get_y (double num[MAXDEG], double x, int deg) {
    double ret = 0;
    for (int i = 0; i <= deg; i++) {
        double cur = num[i];
        for (int j = 0; j < deg - i; j++) {
            cur *= x;
        }
        ret += cur;
    }
    return ret;
}
double get_der_y (double num[MAXDEG], double x, int deg) {
    double ret = 0;
    for (int i = 0; i <= deg - 1; i++) {
        double cur = num[i];
        cur *= (deg - i);
        for (int j = 0; j < deg - i - 1; j++) {
            cur *= x;
        }
        ret += cur;
    }
    return ret;
}

int main () {
    int deg;
    scanf("%d", &deg);
    double num[MAXDEG] = {};

    for (int i = 0; i <= deg; i++) {
        scanf("%lf", &num[i]);
    }
    int t;
    scanf("%d", &t);
    double x;
    scanf("%lf", &x);
    for (int tt = 0; tt < t; tt++) {
        
        printf("%.4lf %.4lf\n", x, get_y(num, x, deg));
        x -= get_y(num, x, deg) / get_der_y(num, x, deg);
        
    }
}