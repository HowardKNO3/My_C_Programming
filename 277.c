#include <stdio.h>
#include <stdbool.h>
#define MAXLEN 20
void print_side_format (int i, int w, bool left, bool right) {
    if (left) {
        printf("%d", i);
    } else {
        printf(" ");
    }
    for (int j = 0; j < w - 3; j++) {
        printf(" ");
    }
    if (right) {
        printf("%d", i);
    } else {
        printf(" ");
    }
    printf(" ");
}
void print_mid_format (int i, int w, bool mid) {
    if (mid) {
        for (int j = 0; j < w; j++) {
            if (j >= 1 && j <= w - 3) {
                printf("%d", i);
            } else {
                printf(" ");
            }
        }
    }
    else {
        for (int l = 0; l < w; l++) {
            printf(" ");
        }
    }
}

int main () {
    char s[MAXLEN];
    while (scanf("%s", &s) != EOF)
    {
        int w, h;
        scanf("%d%d", &w, &h);
        int size = 0;
        while (s[size] <= '9' && s[size] >= '0') {
            size++;
        }
        //printf(" ");
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < size; j++) {
                int cur = (int)(s[j] - '0');
                if (i == 0) {
                    bool mid = (cur == 0) || (cur == 2) || (cur == 3) || (cur == 5) || (cur == 6) || (cur == 7) || (cur == 8) || (cur == 9);
                    print_mid_format(cur, w, mid);
                } else if (i > 0 && i < h / 2) {
                    bool left = (cur == 0) || (cur == 4) || (cur == 5) || (cur == 6) || (cur == 7) || (cur == 8) || (cur == 9);
                    bool right = (cur == 0) || (cur == 1) || (cur == 2) || (cur == 3) || (cur == 4) || (cur == 7) || (cur == 8) || (cur == 9);
                    print_side_format(cur, w, left, right);
                } else if (i == h / 2) {
                    bool mid = (cur == 2) || (cur == 3) || (cur == 4) || (cur == 5) || (cur == 6) || (cur == 8) || (cur == 9);
                    print_mid_format(cur, w, mid);
                } else if (i > h / 2 && i < h - 1) {
                    bool left = (cur == 0) || (cur == 2) || (cur == 6) || (cur == 8);
                    bool right = (cur == 0) || (cur == 1) || (cur == 3) || (cur == 4) || (cur == 5) || (cur == 6) || (cur == 7) || (cur == 8) || (cur == 9);
                    print_side_format(cur, w, left, right);
                } else {
                    bool mid = (cur == 0) || (cur == 2) || (cur == 3) || (cur == 5) || (cur == 6) || (cur == 8);
                    print_mid_format(cur, w, mid);
                }
                
            }
            printf("\n");
        }
    }
}