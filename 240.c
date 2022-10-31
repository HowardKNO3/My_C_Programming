#include <stdio.h>
#include <stdbool.h>

int main () {
    int t;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++){
        int a1, a2, b1, b2, c1, c2, d1, d2;
        scanf("%d%d%d%d%d%d%d%d", &a1, &a2, &b1, &b2, &c1, &c2, &d1, &d2);
        b1 -= a1;
        b2 -= a2;
        c1 -= a1;
        c2 -= a2;
        d1 -= a1;
        d2 -= a2;
        a1 = a2 = 0;
        int temp;
        
        if (b1 * c2 - b2 * c1 < 0) {
            temp = c1;
            c1 = b1;
            b1 = temp;
            temp = c2;
            c2 = b2;
            b2 = temp;
            
        }
        if (c1 * d2 - c2 * d1 < 0) {
            temp = d1;
            d1 = c1;
            c1 = temp;
            temp = d2;
            d2 = c2;
            c2 = temp;
            
        }
        if (b1 * c2 - b2 * c1 < 0) {
            temp = c1;
            c1 = b1;
            b1 = temp;
            temp = c2;
            c2 = b2;
            b2 = temp;
            
        }
        
        
        bool is_right = false;
        
        if (b1 * d1 + b2 * d2 == 0) {
            bool d_is_right = (d1 * c1 + d2 * c2) - (d1 * d1 + d2 * d2) == 0;
            bool b_is_right = (b1 * c1 + b2 * c2) - (b1 * b1 + b2 * b2) == 0;
            if (d_is_right && b_is_right) {
                is_right = true;
            }
        }
        bool is_equal = false;
        
        if (b1 * b1 + b2 * b2 == d1 * d1 + d2 * d2) {
            is_equal = (b1 + d1 == c1) && (b2 + d2 == c2);
        }
        
        if (is_right && is_equal) {
            printf("square\n");
        } else if (is_right) {
            printf("rectangle\n");
        } else if (is_equal) {
            printf("diamond\n");
        } else {
            printf("other\n");
        }
        
        #ifdef DEBUG
            printf("%d %d %d %d %d %d\n", b1, b2, c1, c2, d1, d2);
        #endif
    }
    
}